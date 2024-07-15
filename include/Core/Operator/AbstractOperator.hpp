#ifndef APALINEA_CORE_OPERATOR_ABSTRACTOPERATOR_HPP
#define APALINEA_CORE_OPERATOR_ABSTRACTOPERATOR_HPP

#include <stdexcept>
#include "Core/Tuple/Tuple.hpp"
#include "Core/Operator/IOperator.hpp"

namespace Apalinea::Core::Link {
    class AbstractLink;
}

namespace Apalinea::Core::Operator {
    class AbstractOperator : public IOperator {
    public:
        AbstractOperator() :
            vProcessed(false),
            vProcessing(false),
            vProcessState(Core::Operator::OperatorProcessState::CONTINUE),
            vTimeBasedExecuted(false) {
        }

        friend class Apalinea::Core::Link::AbstractLink;

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
        bool vTimeBasedExecuted;

        [[maybe_unused]] [[nodiscard]] virtual bool isTimeBasedExecutionNeeded() const = 0;

        [[maybe_unused]] void setTimeBasedExecuted(bool pTimeBasedExecuted) {
            this->vTimeBasedExecuted = pTimeBasedExecuted;
        }
    };
} // Apalinea::Core::Operator

#endif //APALINEA_CORE_OPERATOR_ABSTRACTOPERATOR_HPP
