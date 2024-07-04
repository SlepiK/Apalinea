#ifndef APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP
#define APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP

#include <chrono>
#include <optional>
#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Power/Power.hpp"
#include "Core/Type/Datatype/DtFloat.hpp"

namespace Apalinea::Operator::PipeOperator {
    class [[maybe_unused]] CalculatorPipeOperator
            : public Core::Operator::AbstractPipeOperator {
    public:

        [[maybe_unused]] void setThreshold(int threshold) {
            this->vThreshold = std::chrono::milliseconds(threshold);
        }

    private:
        std::optional<std::chrono::steady_clock::time_point> vLast;
        int vRotationPerKWh = 0;
        bool vRotationPerKWhSet = false;
        Core::Type::Datatype::DtFloat energy;
        std::chrono::milliseconds vThreshold = std::chrono::milliseconds(30);

        static std::chrono::steady_clock::time_point getCurrentTimePoint() {
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

            if(this->vLast.has_value()) {
                std::chrono::steady_clock::time_point current = getCurrentTimePoint();
                std::chrono::milliseconds rotationTime = std::chrono::duration_cast<std::chrono::milliseconds>(current - this->vLast.value());

                if(rotationTime > vThreshold) {
                    energy = Core::Type::Datatype::DtFloat(1.0f / static_cast<float>(this->vRotationPerKWh));
                    this->vLast = current;
                    vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                } else {
                    energy = Core::Type::Datatype::DtFloat(0.0f);
                    vProcessState = Core::Operator::OperatorProcessState::BREAK;
                }
            } else {
                //initial process, no red mark was detected before this event.
                this->vLast = getCurrentTimePoint();
                vProcessState = Core::Operator::OperatorProcessState::BREAK;
            }
            outputTuple.clear();
            outputTuple.addItem(std::string("energy"),Core::Type::Datatype::DtFloat(energy));
        }
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP
