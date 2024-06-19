//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_OPERATOR_ABSTRACTOPERATOR_HPP
#define STREAM_V1_OPERATOR_ABSTRACTOPERATOR_HPP

#include <stdexcept>
#include "Core/Tuple/Tuple.hpp"
#include "Core/Operator/IOperator.hpp"

namespace Apalinea::Core::Operator {

    class AbstractOperator : public IOperator {
    public:
        AbstractOperator() : vProcessed(false), vProcessing(false), vProcessState(Core::Operator::OperatorProcessState::CONTINUE) {
        }

        ~AbstractOperator() override = default;

        [[nodiscard]] Core::Operator::OperatorProcessState getOperatorProcessState() const final {
            return vProcessState;
        }

        [[nodiscard]] bool isProcessing() const override {
            return this->vProcessing;
        }

        [[nodiscard]] bool isProcessed() const override {
            return this->vProcessed;
        }

    protected:
        Core::Operator::OperatorProcessState vProcessState;
        bool vProcessing;
        bool vProcessed;
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_ABSTRACTOPERATOR_HPP
