#ifndef APALINEA_CORE_LINK_SINKLINK_HPP
#define APALINEA_CORE_LINK_SINKLINK_HPP

#include <utility>
#include <memory>
#include "Core/Link/AbstractLink.hpp"
#include "Core/Link/Wrapper/LinkWrapper.hpp"

namespace Apalinea::Core::Link {
    template<typename SinkOperator>
    class SinkLink : public AbstractLink, public LinkWrapper {
        static_assert(IsBasedOnAbstractSinkOperator<SinkOperator>::value,"SinkOperator must be based on AbstractSinkOperator!");
    public:
        explicit SinkLink(SinkOperator&& sinkOperator, std::shared_ptr<Core::Executor::IExecutor> executor) :
                AbstractLink(executor),
                vOperator(std::forward<SinkOperator>(sinkOperator)), inputTuple() {
        }

        explicit SinkLink(SinkOperator& sinkOperator, std::shared_ptr<Core::Executor::IExecutor> executor) :
                AbstractLink(executor),
                vOperator(std::move(sinkOperator)), inputTuple() {
        }

        SinkLink(SinkLink&& other) noexcept
                : vOperator(std::move(other.vOperator)), inputTuple(std::move(other.inputTuple)) {
        }

        ~SinkLink() override = default;

        SinkOperator& getOperator() {
            return this->vOperator;
        }

        void setInputTupleR(Core::Tuple::Tuple& tuple) override {
            if(!this->vProcessing) {
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
            if(!this->vProcessing) {
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
                if(this->isTimeBasedExecutionNeeded()) {
                    this->exec();
                }
                return;
            } else this->vNewDataAvailable = false;
            if(this->vOperator.getOperatorMode() == Core::Operator::OperatorMode::TASK) {
                this->executor.get()->addTask([this] { this->exec(); });
            } else if(this->vOperator.getOperatorMode() == Core::Operator::OperatorMode::MAIN) {
                this->exec();
            }
        }

        void setOperatorProcessState(Core::Operator::OperatorProcessState state) override {
            this->vState = state;
        }

        std::optional<std::reference_wrapper<const std::vector<std::shared_ptr<LinkWrapper>>>> getLinks() override {
            return std::nullopt;
        }

        [[nodiscard]] LinkType getType() const override {
            return LinkType::SINK;
        }

    private:
        SinkOperator vOperator;
        Core::Tuple::Tuple inputTuple;

    protected:
        void exec() {
            try {
                if (this->vProcessing) throw std::runtime_error("(Sink-)Link is already processing!");
                if (this->isTimeBasedExecutionNeeded() && this->vTimeBasedExecuted) this->vTimeBasedExecuted = false;
                if (this->vProcessed) this->vProcessed = false;
                if (!this->vProcessing) this->vProcessing = true;

                if(this->vState == Core::Operator::OperatorProcessState::CONTINUE || this->isTimeBasedExecutionNeeded()) {
                    if(this->isTimeBasedExecutionNeeded()) this->vOperator.setTimeBasedExecuted(true);
                    this->vOperator.process(this->inputTuple);
                    if(this->isTimeBasedExecutionNeeded()) this->vOperator.setTimeBasedExecuted(false);
                }

                this->inputTuple.clear();

                this->vProcessing = false;
                this->vProcessed = true;
                if (this->isTimeBasedExecutionNeeded() && !this->vTimeBasedExecuted) this->vTimeBasedExecuted = true;
            } catch (std::exception& exc) {
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR,Core::Log::getFilename(__FILE__),__LINE__,exc.what());
            }
        }

        [[maybe_unused]] [[nodiscard]] bool isTimeBasedExecutionNeeded() const override {
            return this->vOperator.isTimeBasedExecutionNeeded();
        }
    };

    template<typename SinkOperator>
    using SinkLinkPtr = std::shared_ptr<SinkLink<SinkOperator>>;
    template<typename SinkOperator>
    using SinkLinkUPtr [[maybe_unused]] = std::unique_ptr<SinkLink<SinkOperator>>;
} // Apalinea::Core::Link

#endif //APALINEA_CORE_LINK_SINKLINK_HPP
