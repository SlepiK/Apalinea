#ifndef APALINEA_CORE_OPERATOR_IOPERATOR_HPP
#define APALINEA_CORE_OPERATOR_IOPERATOR_HPP

#include "Core/Operator/Type/OperatorMode.hpp"
#include "Core/Operator/Type/OperatorType.hpp"
#include "Core/Operator/ProcessState/OperatorProcessState.hpp"
#include "Core/Heartbeat/IHeartbeatProcess.hpp"

namespace Apalinea::Core::Operator {
    class IOperator : public Apalinea::Core::Heartbeat::IHeartbeatProcess {
    public:
        virtual ~IOperator() = default;

        [[maybe_unused]] [[nodiscard]] virtual Core::Operator::OperatorType getOperatorType() const = 0;

        [[nodiscard]] virtual Core::Operator::OperatorProcessState getOperatorProcessState() const = 0;

        [[maybe_unused]] [[nodiscard]] virtual bool isProcessing() const = 0;

        [[maybe_unused]] [[nodiscard]] virtual bool isProcessed() const = 0;

        [[nodiscard]] virtual Core::Operator::OperatorMode getOperatorMode() const = 0;

        void handleHeartbeat(std::optional<std::chrono::steady_clock::time_point> hbTP, Core::Tuple::Tuple &outputTuple) override {
            (void(0));
        }
    };
} // Apalinea::Core::Operator

#endif //APALINEA_CORE_OPERATOR_IOPERATOR_HPP
