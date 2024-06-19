#ifndef APALINEA_CORE_LINK_LINKTRAIT_HPP
#define APALINEA_CORE_LINK_LINKTRAIT_HPP

#include <type_traits>
#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Core/Operator/SinkOperator/AbstractSinkOperator.hpp"

namespace Apalinea::Core::Link {
    template<typename T>
    struct IsBasedOnAbstractPipeOperator {
        static constexpr bool value = std::is_base_of<Core::Operator::AbstractPipeOperator, T>::value;
    };

    template<typename T>
    struct IsBasedOnAbstractSourceOperator {
        static constexpr bool value = std::is_base_of<Core::Operator::AbstractSourceOperator, T>::value;
    };

    template<typename T>
    struct IsBasedOnAbstractSinkOperator {
        static constexpr bool value = std::is_base_of<Core::Operator::AbstractSinkOperator, T>::value;
    };
} // Apalinea::Core::Link

#endif //APALINEA_CORE_LINK_LINKTRAIT_HPP
