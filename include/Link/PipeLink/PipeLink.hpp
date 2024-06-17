//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_PIPELINK_HPP
#define STREAM_V1_LINK_PIPELINK_HPP

#include <utility>
#include <vector>
#include <memory>
#include "Link/AbstractLink.hpp"
#include "Link/SinkLink/SinkLink.hpp"
#include "Link/Wrapper/LinkWrapper.hpp"

namespace Energyleaf::Stream::V1::Link {

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

        PipeOperator &getOperator() {
            return this->vOperator;
        }

        void setInputTupleR(Tuple::Tuple &tuple) override {
            if (!this->vProcessing) {
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
            if (!this->vProcessing) {
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

        void setOperatorProcessState(Operator::OperatorProcessState state) override {
            this->vState = state;
            for (LinkIterator iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                (*iterator)->setOperatorProcessState(state);
            }
        }

        std::optional<std::reference_wrapper<const std::vector<std::shared_ptr<LinkWrapper>>>> getLinks() override {
            return std::cref(this->vLinks);
        }

        LinkType getType() const override {
            return LinkType::PIPE;
        }

    private:
        PipeOperator vOperator;
        Tuple::Tuple inputTuple;
        std::vector<std::shared_ptr<LinkWrapper>> vLinks;
        using LinkIterator = typename std::vector<std::shared_ptr<LinkWrapper>>::iterator;
    protected:
        void exec() {
            if (this->vProcessing) throw std::runtime_error("(Pipe-)Link is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            if(this->vState == Operator::OperatorProcessState::CONTINUE) {
                Tuple::Tuple outputTuple;
                this->vOperator.process(this->inputTuple, outputTuple);
                this->inputTuple.clear();
                this->vState = this->vOperator.getOperatorProcessState();

                for (LinkIterator iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                    if (this->vState == Operator::OperatorProcessState::CONTINUE) {
                        (*iterator)->setInputTuple(outputTuple);
                    } else {
                        (*iterator)->setOperatorProcessState(this->vState);
                    }
                }
                outputTuple.clear();
            } else {
                this->inputTuple.clear();
            }

            this->vProcessing = false;
            this->vProcessed = true;
        }
    };

    template<typename PipeOperator>
    using PipeLinkPtr = std::shared_ptr<PipeLink<PipeOperator>>;
    template<typename PipeOperator>
    using PipeLinkUPtr = std::unique_ptr<PipeLink<PipeOperator>>;
    template <typename PipeOperator>
    [[deprecated("Use Plan::createPipe() instead. Look for usage in the demo.")]]
    PipeLinkUPtr<PipeOperator> make_PipeLinkUPtr() {
        return std::make_unique<PipeLink<PipeOperator>>(std::forward<PipeOperator>(PipeOperator()),nullptr);
    }

} // Stream::V1::Link

#endif //STREAM_V1_LINK_PIPELINK_HPP

