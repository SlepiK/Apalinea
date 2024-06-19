#ifndef APALINEA_CORE_LINK_LINKWRAPPER_HPP
#define APALINEA_CORE_LINK_LINKWRAPPER_HPP

#include "Core/Link/IBaseLink.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Operator/ProcessState/OperatorProcessState.hpp"

namespace Apalinea::Core::Link {
    class LinkWrapper : virtual public IBaseLink {
    public:
        ~LinkWrapper() override = default;

        virtual void setInputTuple(Core::Tuple::Tuple tuple) = 0;

        virtual void setInputTupleR(Core::Tuple::Tuple& tuple) = 0;

        virtual void setOperatorProcessState(Core::Operator::OperatorProcessState state) = 0;
    };
} // Apalinea::Core::Link

#endif //APALINEA_CORE_LINK_LINKWRAPPER_HPP
