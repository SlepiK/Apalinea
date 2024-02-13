//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_OPERATOR_ABSTRACTOPERATOR_HPP
#define STREAM_V1_OPERATOR_ABSTRACTOPERATOR_HPP

#include "IOperator.hpp"
#include <stdexcept>

namespace Energyleaf::Stream::V1::Operator {

    class AbstractOperator : public IOperator {
    public:
        AbstractOperator() : vProcessed(false), vProcessing(false), vProcessState(OperatorProcessState::CONTINUE) {
        }

        ~AbstractOperator() override = default;

        [[nodiscard]] bool isProcessing() const override;

        [[nodiscard]] bool isProcessed() const override;

        [[nodiscard]] OperatorProcessState getOperatorProcessState() const final {
            return vProcessState;
        }

    protected:
        OperatorProcessState vProcessState;
        bool vProcessing;
        bool vProcessed;
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_ABSTRACTOPERATOR_HPP
