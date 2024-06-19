//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_OPERATOR_OPERATORSTATE_HPP
#define STREAM_V1_OPERATOR_OPERATORSTATE_HPP

namespace Apalinea::Core::Operator {

    enum class OperatorProcessState : int {
        CONTINUE = 0,
        STOP = 1,
        BREAK = 2
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_OPERATORSTATE_HPP
