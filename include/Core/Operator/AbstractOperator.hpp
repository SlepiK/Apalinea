#ifndef APALINEA_CORE_OPERATOR_ABSTRACTOPERATOR_HPP
#define APALINEA_CORE_OPERATOR_ABSTRACTOPERATOR_HPP

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
} // Apalinea::Core::Operator

#endif //APALINEA_CORE_OPERATOR_ABSTRACTOPERATOR_HPP
