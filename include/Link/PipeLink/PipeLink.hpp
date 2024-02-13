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
              public LinkWrapper<typename IsBasedOnAbstractPipeOperator<PipeOperator>::InputTuple> {
        static_assert(IsBasedOnAbstractPipeOperator<PipeOperator>::value,
                      "PipeOperator must be based on AbstractPipeOperator!");
    public:

        using InputTuple = typename IsBasedOnAbstractPipeOperator<PipeOperator>::InputTuple;
        using OutputTuple = typename IsBasedOnAbstractPipeOperator<PipeOperator>::OutputTuple;

        explicit PipeLink(PipeOperator &&pipeOperator)
                : vOperator(std::forward<PipeOperator>(pipeOperator)), inputTuple() {
        }

        explicit PipeLink(PipeOperator &pipeOperator)
                : vOperator(std::move(pipeOperator)) , inputTuple()  {
        }

        PipeLink(PipeLink &&other) noexcept
                : vOperator(std::move(other.vOperator)), inputTuple(std::move(other.inputTuple)) {
        }

        ~PipeLink() override = default;

        PipeOperator &getOperator() {
            return this->vOperator;
        }

        void setInputTupleR(InputTuple &tuple) override {
            if (!this->vProcessing) {
                this->inputTuple = tuple;
            } else {
                throw std::runtime_error("Link is processing!");
            }
        }

        void setInputTuple(InputTuple tuple) override {
            if (!this->vProcessing) {
                this->inputTuple = tuple;
            } else {
                throw std::runtime_error("Link is processing!");
            }
        }

        void process() override {
            if (this->vProcessing) throw std::runtime_error("Link is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            if(this->vState == Operator::OperatorProcessState::CONTINUE) {
                OutputTuple outputTuple;
                this->vOperator.process(this->inputTuple, outputTuple);
                this->inputTuple.clear();
                this->vState = this->vOperator.getOperatorProcessState();

                for (LinkIterator iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                    if (this->vState == Operator::OperatorProcessState::CONTINUE) {
                        (*iterator)->setInputTuple(OutputTuple(outputTuple));
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

        template<typename PipeOperatorNext>
        void connect(const std::shared_ptr<PipeLink<PipeOperatorNext>> &nextLink) {
            static_assert(std::is_same_v<OutputTuple, typename PipeLink<PipeOperatorNext>::InputTuple>,
                          "InputTuple types must be the same for connection.");
            this->vLinks.push_back(nextLink);
        }

        template<typename SinkOperator>
        void connect(const SinkLinkPtr<SinkOperator>& nextLink) {
            static_assert(std::is_same_v<OutputTuple, typename SinkLink<SinkOperator>::InputTuple>,
                          "InputTuple types must be the same for connection.");
            this->vLinks.push_back(nextLink);
        }

        void setOperatorProcessState(Operator::OperatorProcessState state) override {
            this->vState = state;
            for (LinkIterator iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                (*iterator)->setOperatorProcessState(state);
            }
        }

    private:
        PipeOperator vOperator;
        InputTuple inputTuple;
        std::vector<std::shared_ptr<LinkWrapper<OutputTuple>>> vLinks;
        using LinkIterator = typename std::vector<std::shared_ptr<LinkWrapper<OutputTuple>>>::iterator;
    protected:
    };

    template<typename PipeOperator>
    using PipeLinkPtr = std::shared_ptr<PipeLink<PipeOperator>>;
    template<typename PipeOperator>
    using PipeLinkUPtr = std::unique_ptr<PipeLink<PipeOperator>>;
    template <typename PipeOperator>
    PipeLinkUPtr<PipeOperator> make_PipeLinkUPtr() {
        return std::make_unique<PipeLink<PipeOperator>>(std::forward<PipeOperator>(PipeOperator()));
    }

} // Stream::V1::Link

#endif //STREAM_V1_LINK_PIPELINK_HPP
