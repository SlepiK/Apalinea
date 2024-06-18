//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_SINKLINK_HPP
#define STREAM_V1_LINK_SINKLINK_HPP

#include <utility>
#include <memory>
#include "Link/AbstractLink.hpp"
#include "Link/Wrapper/LinkWrapper.hpp"

namespace Energyleaf::Stream::V1::Link {

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

        void setInputTupleR(Tuple::Tuple& tuple) override {
            if(!this->vProcessing) {
                this->inputTuple = tuple;
                this->vNewDataAvailable = true;
                if(this->vOperator.getOperatorMode() == Operator::OperatorMode::DIRECT) {
                    this->exec();
                }
            } else {
                //throw std::runtime_error("Link is processing!");
                //ToDo: Add log functionality for this event.
                return;
            }
        }

        void setInputTuple(Tuple::Tuple tuple) override {
            if(!this->vProcessing) {
                this->inputTuple = tuple;
                this->vNewDataAvailable = true;
                if(this->vOperator.getOperatorMode() == Operator::OperatorMode::DIRECT) {
                    this->exec();
                }
            } else {
                //throw std::runtime_error("Link is processing!");
                //ToDo: Add log functionality for this event.
                return;
            }
        }

        void process() override {
            if (!this->vNewDataAvailable) return;
            else this->vNewDataAvailable = false;
            if(this->vOperator.getOperatorMode() == Operator::OperatorMode::TASK) {
                this->executor.get()->addTask([this] { this->exec(); });
            } else if(this->vOperator.getOperatorMode() == Operator::OperatorMode::MAIN) {
                this->exec();
            }
        }

        void setOperatorProcessState(Operator::OperatorProcessState state) override {
            this->vState = state;
        }

        std::optional<std::reference_wrapper<const std::vector<std::shared_ptr<LinkWrapper>>>> getLinks() override {
            return std::nullopt;
        }

        LinkType getType() const override {
            return LinkType::SINK;
        }

    private:
        SinkOperator vOperator;
        Tuple::Tuple inputTuple;
    protected:
        void exec() {
            if (this->vProcessing) throw std::runtime_error("(Sink-)Link is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            if(this->vState == Operator::OperatorProcessState::CONTINUE) {
                this->vOperator.process(this->inputTuple);
            }
            this->inputTuple.clear();

            this->vProcessing = false;
            this->vProcessed = true;
        }
    };

    template<typename SinkOperator>
    using SinkLinkPtr = std::shared_ptr<SinkLink<SinkOperator>>;
    template<typename SinkOperator>
    using SinkLinkUPtr = std::unique_ptr<SinkLink<SinkOperator>>;
    template <typename SinkOperator>
    [[deprecated("Use Plan::createSink() instead. Look for usage in the demo.")]]
    SinkLinkUPtr<SinkOperator> make_SinkLinkUPtr() {
        return std::make_unique<SinkLink<SinkOperator>>(std::forward<SinkOperator>(SinkOperator()),nullptr);
    }

} // Stream::V1::Link

#endif //STREAM_V1_LINK_SINKLINK_HPP
