#ifndef APALINEA_CORE_LINK_PIPELINK_HPP
#define APALINEA_CORE_LINK_PIPELINK_HPP

#include <utility>
#include <vector>
#include <memory>
#include "Core/Link/AbstractLink.hpp"
#include "Core/Link/SinkLink/SinkLink.hpp"
#include "Core/Link/Wrapper/LinkWrapper.hpp"

namespace Apalinea::Core::Link {
    template<typename PipeOperator>
    class PipeLink
            : public AbstractLink,
              public LinkWrapper {
        static_assert(IsBasedOnAbstractPipeOperator<PipeOperator>::value,
                      "PipeOperator must be based on AbstractPipeOperator!");
    public:
        explicit PipeLink(PipeOperator &&pipeOperator, std::shared_ptr<Core::Executor::IExecutor> executor) :
                AbstractLink(executor),
                vOperator(std::forward<PipeOperator>(pipeOperator)), inputTuple() {
        }

        explicit PipeLink(PipeOperator &pipeOperator, std::shared_ptr<Core::Executor::IExecutor> executor) :
                AbstractLink(executor),
                vOperator(std::move(pipeOperator)) , inputTuple()  {
        }

        PipeLink(PipeLink &&other) noexcept
                : vOperator(std::move(other.vOperator)), inputTuple(std::move(other.inputTuple)) {
        }

        ~PipeLink() override = default;

        [[maybe_unused]] PipeOperator &getOperator() {
            return this->vOperator;
        }

        void setInputTupleR(Core::Tuple::Tuple &tuple) override {
            if (!this->vProcessing) {
                this->inputTuple = tuple;
                this->vNewDataAvailable = true;
                if(this->vOperator.getOperatorMode() == Core::Operator::OperatorMode::DIRECT) {
                    this->exec();
                }
            } else {
                if(!this->isTimeBasedExecutionNeeded()) {
                    Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR, Core::Log::getFilename(__FILE__),
                                               __LINE__, "Link is already processing!");
                }
                return;
            }
        }

        void setInputTuple(Core::Tuple::Tuple tuple) override {
            if (!this->vProcessing) {
                this->inputTuple = tuple;
                this->vNewDataAvailable = true;
                if(this->vOperator.getOperatorMode() == Core::Operator::OperatorMode::DIRECT) {
                    this->exec();
                }
            } else {
                if(!this->isTimeBasedExecutionNeeded()) {
                    Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR, Core::Log::getFilename(__FILE__),
                                               __LINE__, "Link is already processing!");
                }
                return;
            }
        }

        void process() override {
            if (!this->vNewDataAvailable) {
                return;
            } else this->vNewDataAvailable = false;
            if(this->vOperator.getOperatorMode() == Core::Operator::OperatorMode::TASK) {
                this->executor.get()->addTask([this] { this->exec(); });
            } else if(this->vOperator.getOperatorMode() == Core::Operator::OperatorMode::MAIN) {
                this->exec();
            }
        }

        template<typename PipeOperatorNext>
        void connect(const std::shared_ptr<PipeLink<PipeOperatorNext>> &nextLink) {
            this->vLinks.push_back(nextLink);
        }

        template<typename SinkOperator>
        void connect(const SinkLinkPtr<SinkOperator>& nextLink) {
            this->vLinks.push_back(nextLink);
        }

        void setOperatorProcessState(Core::Operator::OperatorProcessState state) override {
            this->vState = state;
            for (auto iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                (*iterator)->setOperatorProcessState(state);
            }
        }

        std::optional<std::reference_wrapper<const std::vector<std::shared_ptr<LinkWrapper>>>> getLinks() override {
            return std::cref(this->vLinks);
        }

        [[nodiscard]] LinkType getType() const override {
            return LinkType::PIPE;
        }

    private:
        PipeOperator vOperator;
        Core::Tuple::Tuple inputTuple;
        std::vector<std::shared_ptr<LinkWrapper>> vLinks;
        using LinkIterator [[maybe_unused]] = typename std::vector<std::shared_ptr<LinkWrapper>>::iterator;

    protected:

        void sendHeartbeat() override {
            for (auto iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                if(this->vState == Core::Operator::OperatorProcessState::BREAK) {
                    (*iterator)->vHeartbeatState = Apalinea::Core::Heartbeat::HeartbeatState::HEARTBEAT;
                    (*iterator)->handleHeartbeat();
                }
            }
        }

        void handleHeartbeat() override {
            try {
                if (this->vProcessing) throw std::runtime_error("(Pipe-)Link is already processing! (Heartbeat)");
                if(this->vOperator.getOperatorMode() == Core::Operator::OperatorMode::TASK) {
                    this->executor.get()->addTask([this] { this->execHeartbeat(); });
                } else if(this->vOperator.getOperatorMode() == Core::Operator::OperatorMode::DIRECT) {
                    this->execHeartbeat();
                }
            } catch (std::exception& exc) {
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR,Core::Log::getFilename(__FILE__),__LINE__,exc.what());
            }
        }

        void execHeartbeat() {
            try {
                if (this->vProcessing) throw std::runtime_error("(Pipe-)Link is already processing! (Heartbeat)");
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::INFORMATION,Core::Log::getFilename(__FILE__),__LINE__,"Heartbeat");
                this->vOperator.handleHeartbeat(this->getHeartbeatTimePoint());
                this->vHeartbeatState = Core::Heartbeat::HeartbeatState::NO_HEARTBEAT;
                this->updateHeartbeatTimePoint();
                this->sendHeartbeat();
            } catch (std::exception& exc) {
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR,Core::Log::getFilename(__FILE__),__LINE__,exc.what());
            }
        }

        void exec() {
            try {
                if (this->vProcessing) throw std::runtime_error("(Pipe-)Link is already processing!");
                if (this->vProcessed) this->vProcessed = false;
                if (!this->vProcessing) this->vProcessing = true;


                if(this->vHeartbeatState == Apalinea::Core::Heartbeat::HeartbeatState::HEARTBEAT) {
                    Core::Log::LogManager::log(Core::Log::LogLevelCategory::INFORMATION,Core::Log::getFilename(__FILE__),__LINE__,"Heartbeat");
                    this->vOperator.handleHeartbeat(this->getHeartbeatTimePoint());
                    this->vHeartbeatState = Core::Heartbeat::HeartbeatState::NO_HEARTBEAT;
                    this->updateHeartbeatTimePoint();
                    this->sendHeartbeat();
                } else {
                    if (this->vState == Core::Operator::OperatorProcessState::CONTINUE) {

                        Tuple::Tuple outputTuple;
                        this->vOperator.process(this->inputTuple, outputTuple);

                        this->inputTuple.clear();
                        this->vState = this->vOperator.getOperatorProcessState();

                        for (auto iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                            if (this->vState == Core::Operator::OperatorProcessState::CONTINUE) {
                                (*iterator)->setInputTuple(outputTuple);
                            } else {
                                (*iterator)->setOperatorProcessState(this->vState);
                            }
                        }

                        outputTuple.clear();
                        this->updateHeartbeatTimePoint();
                    }

                    this->inputTuple.clear();

                    if(this->vState == Core::Operator::OperatorProcessState::BREAK) {
                        this->sendHeartbeat();
                    }
                }

                this->vProcessing = false;
                this->vProcessed = true;
            } catch (std::exception& exc) {
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR,Core::Log::getFilename(__FILE__),__LINE__,exc.what());
            }
        }
    };

    template<typename PipeOperator>
    using PipeLinkPtr = std::shared_ptr<PipeLink<PipeOperator>>;
    template<typename PipeOperator>
    using PipeLinkUPtr [[maybe_unused]] = std::unique_ptr<PipeLink<PipeOperator>>;
} // Apalinea::Core::Link

#endif //APALINEA_CORE_LINK_PIPELINK_HPP

