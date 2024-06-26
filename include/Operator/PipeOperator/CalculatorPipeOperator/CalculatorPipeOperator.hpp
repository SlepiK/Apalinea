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
            this->vThreshold = threshold;
        }

    private:
        std::optional<std::chrono::steady_clock::time_point> vLast;
        int vRotationPerKWh = 0;
        bool vRotationPerKWhSet = false;
        Core::Type::Datatype::DtFloat energy;
        int vThreshold = 30;

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
                std::chrono::hours rotationTime = std::chrono::duration_cast<std::chrono::hours>(current - this->vLast.value());

                if(rotationTime.count() > vThreshold) {
                    auto tmpEnergy = static_cast<float>(rotationTime.count());
                    energy = Core::Type::Datatype::DtFloat(tmpEnergy / static_cast<float>(this->vRotationPerKWh));
                    this->vLast = current;
                } else {
                    energy = Core::Type::Datatype::DtFloat(0.0f);
                }
            } else {
                //initial process, no red mark was detected before this event.
                this->vLast = getCurrentTimePoint();
            }
            outputTuple.clear();
            outputTuple.addItem(std::string("Power"),Core::Type::Datatype::DtFloat(energy));
        }
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP
