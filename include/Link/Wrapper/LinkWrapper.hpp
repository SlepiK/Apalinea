//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_LINK_LINKWRAPPER_HPP
#define STREAM_V1_LINK_LINKWRAPPER_HPP

#include "Operator/ProcessState/OperatorProcessState.hpp"

namespace Energyleaf::Stream::V1::Link {
    template<typename InputTuple>
    class LinkWrapper {
    public:
        virtual ~LinkWrapper() = default;
        virtual void setInputTuple(InputTuple tuple) = 0;
        virtual void setInputTupleR(InputTuple& tuple) = 0;
        virtual void setOperatorProcessState(Operator::OperatorProcessState state) = 0;
    private:
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_LINKWRAPPER_HPP
