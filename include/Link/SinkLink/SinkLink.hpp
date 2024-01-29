//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_SINKLINK_HPP
#define STREAM_V1_LINK_SINKLINK_HPP

#include <utility>
#include <memory>
#include "Link/AbstractLink.hpp"
#include "Link/Wrapper/LinkWrapper.hpp"

namespace Stream::V1::Link {

    template<typename SinkOperator>
    class SinkLink : public AbstractLink, public LinkWrapper<typename IsBasedOnAbstractSinkOperator<SinkOperator>::InputTuple> {
        static_assert(IsBasedOnAbstractSinkOperator<SinkOperator>::value,"SinkOperator must be based on AbstractSinkOperator!");
    public:

        using InputTuple = typename IsBasedOnAbstractSinkOperator<SinkOperator>::InputTuple;

        explicit SinkLink(SinkOperator&& sinkOperator)
            : vOperator(std::forward<SinkOperator>(sinkOperator)), inputTuple() {
        }

        explicit SinkLink(SinkOperator& sinkOperator)
                : vOperator(std::move(sinkOperator)), inputTuple() {
        }

        SinkLink(SinkLink&& other) noexcept
            : vOperator(std::move(other.vOperator)), inputTuple(std::move(other.inputTuple)) {
        }

        ~SinkLink() override = default;

        const SinkOperator& getOperator() {
            return this->vOperator;
        }

        void setInputTupleR(InputTuple& tuple) override {
            if(!this->vProcessing) {
                this->inputTuple = tuple;
            } else {
                throw std::runtime_error("Link is processing!");
            }
        }

        void setInputTuple(InputTuple tuple) override {
            if(!this->vProcessing) {
                this->inputTuple = tuple;
            } else {
                throw std::runtime_error("Link is processing!");
            }
        }

        void process() override {
            if (this->vProcessing) throw std::runtime_error("Link is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            this->vOperator.process(this->inputTuple);

            this->vProcessing = false;
            this->vProcessed = true;
        }

    private:
        SinkOperator vOperator;
        InputTuple inputTuple;
    protected:
    };

    template<typename SinkOperator>
    using SinkLinkPtr = std::shared_ptr<SinkLink<SinkOperator>>;
    template<typename SinkOperator>
    using SinkLinkUPtr = std::unique_ptr<SinkLink<SinkOperator>>;
    template <typename SinkOperator>
    SinkLinkUPtr<SinkOperator> make_SinkLinkUPtr() {
        return std::make_unique<SinkLink<SinkOperator>>(std::forward<SinkOperator>(SinkOperator()));
    }

} // Stream::V1::Link

#endif //STREAM_V1_LINK_SINKLINK_HPP
