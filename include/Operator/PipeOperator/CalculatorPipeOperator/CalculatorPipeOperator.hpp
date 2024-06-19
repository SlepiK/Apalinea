#ifndef APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP
#define APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP

#include <chrono>
#include <optional>
#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Power/Power.hpp"
#include "Core/Type/Datatype/DtFloat.hpp"

namespace Apalinea::Operator::PipeOperator {
    class CalculatorPipeOperator
            : public Core::Operator::AbstractPipeOperator {
    public:
        static constexpr float WATT_PER_MILLISECOND = 3600000.0f;
        static constexpr float WATT_PER_SECOND = 3600.0f;
        static constexpr float WATT_PER_MINUTE = 60.0f;
        static constexpr float WATT_PER_HOUR = 1.0f;

        [[deprecated("Send rotation per kwh in stream.")]]
        void setRotationPerKWh(int&& rotation) {
            if(this->vRun) {
                throw std::runtime_error("Operator was already used! Config before first use!");
            }
            this->vRotationPerKWh = rotation;
            this->vRotationPerKWhSet = true;
        }

        enum class CalculationFormat : int {
            MILLISECOND = 0,
            SECOND = 1,
            MINUTE = 2,
            HOUR = 3
        };

        void setCalculationFormat(CalculationFormat format) {
            if(this->vRun) {
                throw std::runtime_error("Operator was already used! Config before first use!");
            }
            switch (format) {
                case CalculationFormat::MILLISECOND:
                    wattPer = WATT_PER_MILLISECOND;
                    break;
                case CalculationFormat::SECOND:
                    wattPer = WATT_PER_SECOND;
                    break;
                case CalculationFormat::MINUTE:
                    wattPer = WATT_PER_MINUTE;
                    break;
                case CalculationFormat::HOUR:
                    wattPer = WATT_PER_HOUR;
                    break;
            }
        }

    private:
        std::optional<std::chrono::steady_clock::time_point> vLast;
        int vRotationPerKWh = 0;
        bool vRotationPerKWhSet = false;
        float wattPer = WATT_PER_SECOND;
        Core::Type::Datatype::DtFloat power;
        bool vRun = false;

        std::chrono::steady_clock::time_point getCurrentTimePoint() {
            return std::chrono::steady_clock::now();
        }

    protected:
        void work(Core::Tuple::Tuple &inputTuple,
                  Core::Tuple::Tuple &outputTuple) override {
            if(!inputTuple.containsItem("State")){
                vProcessState = Core::Operator::OperatorProcessState::BREAK;
                return;
            } else {
                vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
            }

            if(inputTuple.containsItem("RotationKWH")) {
                vRotationPerKWh = inputTuple.getItem<Core::Type::Datatype::DtInt>("RotationKWH").toInt();
                this->vRotationPerKWhSet = true;
            }
            inputTuple.clear();
            if(!this->vRotationPerKWhSet) {
                throw std::runtime_error("Operator was not configured before use! Config before first use!");
            }
            this->vRun = true;

            if(this->vLast.has_value()) {
                std::chrono::steady_clock::time_point current = getCurrentTimePoint();
                std::chrono::milliseconds  rotationTime = std::chrono::duration_cast<std::chrono::milliseconds>(current - this->vLast.value());
                if(rotationTime.count() > 30) {
                    power = Core::Type::Datatype::DtFloat((this->wattPer / rotationTime.count() / this->vRotationPerKWh) * 1000.0f);
                    this->vLast = current;
                } else {
                    power = Core::Type::Datatype::DtFloat(0.0f);
                }
            } else {
                //initial process, no red mark was detected before this event.
                this->vLast = getCurrentTimePoint();
            }
            outputTuple.clear();
            outputTuple.addItem(std::string("Power"),Core::Type::Datatype::DtFloat(power));
        }
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP
