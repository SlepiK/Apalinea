#ifndef APALINEA_CORE_OPERATOR_OPERATORSTATE_HPP
#define APALINEA_CORE_OPERATOR_OPERATORSTATE_HPP

namespace Apalinea::Core::Operator {
    enum class OperatorProcessState : int {
        CONTINUE = 0,
        STOP = 1,
        BREAK = 2
    };
} // Apalinea::Core::Operator

#endif //APALINEA_CORE_OPERATOR_OPERATORSTATE_HPP
