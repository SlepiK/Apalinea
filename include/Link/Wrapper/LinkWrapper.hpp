//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_LINK_LINKWRAPPER_HPP
#define STREAM_V1_LINK_LINKWRAPPER_HPP

#include "Operator/ProcessState/OperatorProcessState.hpp"
#include "Tuple/Tuple.hpp"
#include "Link/IBaseLink.hpp"

namespace Energyleaf::Stream::V1::Link {
    class LinkWrapper : virtual public IBaseLink {
    public:
        virtual ~LinkWrapper() = default;
        virtual void setInputTuple(Tuple::Tuple tuple) = 0;
        virtual void setInputTupleR(Tuple::Tuple& tuple) = 0;
        virtual void setOperatorProcessState(Operator::OperatorProcessState state) = 0;
    private:
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_LINKWRAPPER_HPP
