//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_OPERATOR_OPERATORTYPE_HPP
#define STREAM_V1_OPERATOR_OPERATORTYPE_HPP

namespace Energyleaf::Stream::V1::Operator {

    enum class OperatorType : int {
        SOURCE = 0,
        PIPE = 1,
        SINK = 2
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_OPERATORTYPE_HPP
