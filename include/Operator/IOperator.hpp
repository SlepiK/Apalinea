//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_OPERATOR_IOPERATOR_HPP
#define STREAM_V1_OPERATOR_IOPERATOR_HPP

#include "Type/OperatorType.hpp"
#include "ProcessState/OperatorProcessState.hpp"

namespace Energyleaf::Stream::V1::Operator {

    class IOperator {
    public:
        virtual ~IOperator() = default;

        [[nodiscard]] virtual OperatorType getOperatorType() const = 0;

        [[nodiscard]] virtual OperatorProcessState getOperatorProcessState() const = 0;

        [[nodiscard]] virtual bool isProcessing() const = 0;

        [[nodiscard]] virtual bool isProcessed() const = 0;
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_IOPERATOR_HPP
