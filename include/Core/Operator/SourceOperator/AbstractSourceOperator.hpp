#ifndef APALINEA_CORE_OPERATOR_SOURCEOPERATOR_HPP
#define APALINEA_CORE_OPERATOR_SOURCEOPERATOR_HPP

#include "Core/Operator/AbstractOperator.hpp"

namespace Apalinea::Core::Operator {
    class AbstractSourceOperator : public AbstractOperator {
    public:
        AbstractSourceOperator() = default;

        ~AbstractSourceOperator() override = default;

        [[nodiscard]] Core::Operator::OperatorType getOperatorType() const override {
            return Core::Operator::OperatorType::SOURCE;
        }

        [[nodiscard]] Core::Operator::OperatorMode getOperatorMode() const override {
            return Core::Operator::OperatorMode::TASK;
        }

        virtual void process(Core::Tuple::Tuple& outputTuple) final {
            if (this->vProcessing) throw std::runtime_error("Operator is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            this->work(outputTuple);

            this->vProcessing = false;
            this->vProcessed = true;
        }

    protected:
        virtual void work(Core::Tuple::Tuple& outputTuple) = 0;

        [[maybe_unused]] [[nodiscard]] bool isTimeBasedExecutionNeeded() const override {
            return false;
        }
    };
} // Apalinea::Core::Operator

#endif //APALINEA_CORE_OPERATOR_SOURCEOPERATOR_HPP
