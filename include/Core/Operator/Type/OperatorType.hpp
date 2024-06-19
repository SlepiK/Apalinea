#ifndef APALINEA_CORE_OPERATOR_OPERATORTYPE_HPP
#define APALINEA_CORE_OPERATOR_OPERATORTYPE_HPP

namespace Apalinea::Core::Operator {
    enum class OperatorType : int {
        SOURCE = 0,
        PIPE = 1,
        SINK = 2
    };
} // Apalinea::Core::Operator

#endif //APALINEA_CORE_OPERATOR_OPERATORTYPE_HPP
