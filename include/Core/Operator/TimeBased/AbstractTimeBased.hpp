#ifndef APALINEA_CORE_OPERATOR_TIMEBASEDOPERATOR_HPP
#define APALINEA_CORE_OPERATOR_TIMEBASEDOPERATOR_HPP

#include <chrono>
#include <optional>

namespace Apalinea::Core::Operator {
    class AbstractTimeBased {
    public:
        AbstractTimeBased() = default;

        [[maybe_unused]] [[nodiscard]] virtual bool isTimeBasedExecutionNeeded() const = 0;

        static std::chrono::steady_clock::time_point getCurrentTimePoint() {
            return std::chrono::steady_clock::now();
        }

        [[maybe_unused]] [[nodiscard]] virtual std::chrono::milliseconds getTimeBasedExecutionIterationTime() {
            return std::chrono::milliseconds(1000); //default is 1 second
        }

        [[maybe_unused]] void setTimeBasedExecuted(bool pTimeBasedExecuted) {
            this->vTimeBasedExecuted = pTimeBasedExecuted;
        }

        [[maybe_unused]] [[nodiscard]] bool isExecutableByIterationTime() {
            std::chrono::steady_clock::time_point current = getCurrentTimePoint();
            if(this->vLast.has_value()) {
                if((this->vLast.value() + this->getTimeBasedExecutionIterationTime()) < current) {
                    return true;
                } else {
                    return false;
                }
            } else {
                this->vLast = current;
                return false;
            }
        }

    protected:
        bool vTimeBasedExecuted = false;
        std::optional<std::chrono::steady_clock::time_point> vLast;

    };
} // Apalinea::Core::Operator

#endif //APALINEA_CORE_OPERATOR_TIMEBASEDOPERATOR_HPP
