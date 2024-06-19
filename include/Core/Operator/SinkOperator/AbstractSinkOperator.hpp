//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_OPERATOR_SINKOPERATOR_HPP
#define STREAM_V1_OPERATOR_SINKOPERATOR_HPP

#include "Core/Operator/AbstractOperator.hpp"
#include "Expression/IExpression.hpp"

namespace Apalinea::Core::Operator {

    class AbstractSinkOperator : public AbstractOperator {
    public:
        AbstractSinkOperator() = default;

        ~AbstractSinkOperator() override = default;

        [[nodiscard]] Core::Operator::OperatorType getOperatorType() const override {
            return Core::Operator::OperatorType::SINK;
        }

        [[nodiscard]] Core::Operator::OperatorMode getOperatorMode() const override {
            return Core::Operator::OperatorMode::TASK;
        }

        virtual void process(Core::Tuple::Tuple& inputTuple) final {
            if (this->vProcessing) throw std::runtime_error("Operator is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            this->work(inputTuple);

            this->vProcessing = false;
            this->vProcessed = true;
        }

        void setExpression(Expression::IExpression* exp) {
            if(!exp->isUsed()) {
                this->expression = exp;
                exp->setUsed(true);
            } else {
                throw std::runtime_error("Given AbstractExpression is already in use!");
            }
        }

        Expression::IExpression* getExpression() {
            return this->expression;
        }

    private:
    protected:
        Expression::IExpression* expression{nullptr};
        virtual void work(Core::Tuple::Tuple& inputTuple) = 0;
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_SINKOPERATOR_HPP
