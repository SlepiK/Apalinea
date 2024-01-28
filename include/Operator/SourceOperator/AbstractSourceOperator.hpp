//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_OPERATOR_SOURCEOPERATOR_HPP
#define STREAM_V1_OPERATOR_SOURCEOPERATOR_HPP

#include "Operator/AbstractOperator.hpp"

namespace Stream::V1::Operator {

    template<typename OutputTuple>
    class AbstractSourceOperator : public AbstractOperator {
    public:
        AbstractSourceOperator() = default;

        ~AbstractSourceOperator() override = default;

        [[nodiscard]] OperatorType getOperatorType() const override {
            return OperatorType::SOURCE;
        }

        virtual void process(OutputTuple& outputTuple) final {
            if (this->vProcessing) throw std::runtime_error("Operator is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            this->work(outputTuple);

            this->vProcessing = false;
            this->vProcessed = true;
        }

    private:
    protected:
        virtual void work(OutputTuple& outputTuple) = 0;
    };

} // Stream::V1::Operator

#endif //STREAM_V1_OPERATOR_SOURCEOPERATOR_HPP
