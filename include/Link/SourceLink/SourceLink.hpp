//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_SOURCELINK_HPP
#define STREAM_V1_LINK_SOURCELINK_HPP

#include <utility>
#include <vector>
#include "Link/AbstractLink.hpp"
#include "Link/PipeLink/PipeLink.hpp"
#include "Link/SinkLink/SinkLink.hpp"
#include "Link/Wrapper/LinkWrapper.hpp"

namespace Energyleaf::Stream::V1::Link {

    template<typename SourceOperator>
    class SourceLink : public AbstractLink {
        static_assert(IsBasedOnAbstractSourceOperator<SourceOperator>::value,"SourceOperator must be based on AbstractSourceOperator!");
    public:
        using OutputTuple = typename IsBasedOnAbstractSourceOperator<SourceOperator>::OutputTuple;

        explicit SourceLink(SourceOperator&& sourceOperator)
                : vOperator(std::forward<SourceOperator>(sourceOperator)) {
        }

        explicit SourceLink(SourceOperator& sourceOperator)
                : vOperator(std::move(sourceOperator)) {
        }

        SourceLink(SourceLink &&other) noexcept
                : vOperator(std::move(other.vOperator)) {
        }

        ~SourceLink() override = default;

        SourceOperator& getOperator() {
            return this->vOperator;
        }

        void process() override {
            if (this->vProcessing) throw std::runtime_error("Link is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            if(this->vState == Operator::OperatorProcessState::CONTINUE || this->vState == Operator::OperatorProcessState::BREAK) {
                OutputTuple outputTuple;
                this->vOperator.process(outputTuple);
                this->vState = this->vOperator.getOperatorProcessState();

                for (LinkIterator iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                    if (this->vState == Operator::OperatorProcessState::CONTINUE) {
                        (*iterator)->setInputTuple(outputTuple);
                        (*iterator)->setOperatorProcessState(this->vState);
                    } else {
                        (*iterator)->setOperatorProcessState(this->vState);
                    }
                }
                outputTuple.clear();
            }

            this->vProcessing = false;
            this->vProcessed = true;
        }

        template<typename PipeOperator>
        void connect(const PipeLinkPtr<PipeOperator> &nextLink) {
            static_assert(std::is_same_v<OutputTuple, typename PipeLink<PipeOperator>::InputTuple>,
                          "InputTuple types must be the same for connection.");
            this->vLinks.push_back(nextLink);
        }

        template<typename SinkOperator>
        void connect(const SinkLinkPtr<SinkOperator> &nextLink) {
            static_assert(std::is_same_v<OutputTuple, typename SinkLink<SinkOperator>::InputTuple>,
                          "InputTuple types must be the same for connection.");
            this->vLinks.push_back(nextLink);
        }

    private:
        SourceOperator vOperator;
        std::vector<std::shared_ptr<LinkWrapper<OutputTuple>>> vLinks;
        using LinkIterator = typename std::vector<std::shared_ptr<LinkWrapper<OutputTuple>>>::iterator;
    protected:
    };

    template<typename SourceOperator>
    using SourceLinkPtr = std::shared_ptr<SourceLink<SourceOperator>>;
    template<typename SourceOperator>
    using SourceLinkUPtr = std::unique_ptr<SourceLink<SourceOperator>>;
    template <typename SourceOperator>
    SourceLinkUPtr<SourceOperator> make_SourceLinkUPtr() {
        return std::make_unique<SourceLink<SourceOperator>>(std::forward<SourceOperator>(SourceOperator()));
    }

} // Stream::V1::Link

#endif //STREAM_V1_LINK_SOURCELINK_HPP
