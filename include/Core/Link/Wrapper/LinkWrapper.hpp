//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_LINK_LINKWRAPPER_HPP
#define STREAM_V1_LINK_LINKWRAPPER_HPP

#include "Core/Link/IBaseLink.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Operator/ProcessState/OperatorProcessState.hpp"

namespace Apalinea::Core::Link {
    class LinkWrapper : virtual public IBaseLink {
    public:
        virtual ~LinkWrapper() = default;
        virtual void setInputTuple(Core::Tuple::Tuple tuple) = 0;
        virtual void setInputTupleR(Core::Tuple::Tuple& tuple) = 0;
        virtual void setOperatorProcessState(Core::Operator::OperatorProcessState state) = 0;
    private:
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_LINKWRAPPER_HPP
