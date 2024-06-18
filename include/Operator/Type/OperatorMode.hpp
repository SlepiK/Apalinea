//
// Created by SlepiK on 09.06.24.
//

#ifndef STREAM_V1_OPERATOR_OPERATORMODE_HPP
#define STREAM_V1_OPERATOR_OPERATORMODE_HPP

namespace Energyleaf::Stream::V1::Operator {

    enum class OperatorMode : int {
        TASK = 0,
        DIRECT = 1,
        MAIN = 2
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_OPERATORMODE_HPP
