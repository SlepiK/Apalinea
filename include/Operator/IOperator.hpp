//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_OPERATOR_IOPERATOR_HPP
#define STREAM_V1_OPERATOR_IOPERATOR_HPP

#include "Type/OperatorType.hpp"

namespace Stream::V1::Operator {

    class IOperator {
    public:
        virtual ~IOperator() = default;
        [[nodiscard]] virtual OperatorType getOperatorType() const = 0;
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_IOPERATOR_HPP
