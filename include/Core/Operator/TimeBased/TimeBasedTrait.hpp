#ifndef APALINEA_CORE_OPERATOR_TIMEBASEDTRAIT_HPP
#define APALINEA_CORE_OPERATOR_TIMEBASEDTRAIT_HPP

#include "Core/Operator/TimeBased/AbstractTimeBased.hpp"

namespace Apalinea::Core::Operator {
    template<typename T>
    struct is_time_based_executable {
        static constexpr bool value = std::is_base_of<Core::Operator::AbstractTimeBased, T>::value;
    };
} // Apalinea::Core::Operator

#endif //APALINEA_CORE_OPERATOR_TIMEBASEDTRAIT_HPP
