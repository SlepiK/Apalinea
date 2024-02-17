//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_OPERATOR_PIPEOPERATOR_HPP
#define STREAM_V1_OPERATOR_PIPEOPERATOR_HPP

#include "Operator/AbstractOperator.hpp"

namespace Energyleaf::Stream::V1::Operator {

    class AbstractPipeOperator : public AbstractOperator {
    public:
        AbstractPipeOperator() = default;

        ~AbstractPipeOperator() override = default;

        [[nodiscard]] OperatorType getOperatorType() const override {
            return OperatorType::PIPE;
        }

        virtual void process(Tuple::Tuple& inputTuple, Tuple::Tuple& outputTuple) final {
            if (this->vProcessing) throw std::runtime_error("Operator is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            this->work(inputTuple, outputTuple);

            this->vProcessing = false;
            this->vProcessed = true;
        }

    private:
    protected:
        virtual void work(Tuple::Tuple& inputTuple, Tuple::Tuple& outputTuple) = 0;
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_PIPEOPERATOR_HPP
