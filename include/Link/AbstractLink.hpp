//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_ABSTRACTLINK_HPP
#define STREAM_V1_LINK_ABSTRACTLINK_HPP

#include "ILink.hpp"
#include "Trait/LinkTrait.hpp"
#include "Tuple/Tuple.hpp"

namespace Energyleaf::Stream::V1::Link {

    class AbstractLink : public ILink {
    public:
        AbstractLink() : vProcessed(false), vProcessing(false) , vState(Operator::OperatorProcessState::CONTINUE){
        }

        ~AbstractLink() override = default;

        [[nodiscard]] bool isProcessing() const override {
            return this->vProcessing;
        }

        [[nodiscard]] bool isProcessed() const override {
            return this->vProcessed;
        }

    private:
    protected:
        bool vProcessing;
        bool vProcessed;
        Operator::OperatorProcessState vState;
    };

} // Stream::V1::Link

#endif //STREAM_V1_LINK_ABSTRACTLINK_HPP
