#ifndef APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP
#define APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP

#include <chrono>
#include <optional>
#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Power/Power.hpp"
#include "Core/Type/Datatype/DtFloat.hpp"

namespace Apalinea::Operator::PipeOperator {
    class [[maybe_unused]] EnergyCalculatorPipeOperator
            : public Core::Operator::AbstractPipeOperator {
    public:

        [[maybe_unused]] void setThreshold(unsigned int threshold) {
            this->vThreshold = std::chrono::milliseconds(threshold);
        }

        [[maybe_unused]] void setTimeWindow(unsigned int timeWindow) {
            this->vTimeWindow = std::chrono::milliseconds(timeWindow);
        }

        [[maybe_unused]] unsigned int getThreshold() {
            return this->vThreshold.count();
        }

        [[maybe_unused]] unsigned int getTimeWindow() {
            return this->vTimeWindow.count();
        }

        [[maybe_unused]] [[nodiscard]] bool isTimeBasedExecutionNeeded() const override {
            //we want that this operator can also be executed outside the pipeline
            return true;
        }

    private:
        std::optional<std::chrono::steady_clock::time_point> vLast;
        int vRotationPerKWh = 0;
        bool vRotationPerKWhSet = false;
        Core::Type::Datatype::DtFloat energyCol = Core::Type::Datatype::DtFloat(0.0f);
        Core::Type::Datatype::DtFloat energyOut = Core::Type::Datatype::DtFloat(0.0f);
        std::chrono::milliseconds vThreshold = std::chrono::milliseconds(30);
        std::chrono::milliseconds vTimeWindow = std::chrono::milliseconds(1000); //Default is 1 second

        static std::chrono::steady_clock::time_point getCurrentTimePoint() {
            return std::chrono::steady_clock::now();
        }

    protected:
        void work(Core::Tuple::Tuple &inputTuple,
                  Core::Tuple::Tuple &outputTuple) override {
            if(!inputTuple.containsItem("State") && !vTimeBasedExecuted){
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
            if(!this->vRotationPerKWhSet && !vTimeBasedExecuted) {
                throw std::runtime_error("Operator was not configured before use! Config before first use!");
            }

            std::chrono::steady_clock::time_point current = getCurrentTimePoint();

            if(this->vLast.has_value()) {
                if(vTimeBasedExecuted && (this->vLast.value() + this->vTimeWindow) < current) {
                    //the operator is executed outside the pipeline
                    energyOut = energyCol;
                    this->vLast = current;
                    energyCol = Core::Type::Datatype::DtFloat(0.0f);
                    vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                    outputTuple.clear();
                    outputTuple.addItem(std::string("energy"),Core::Type::Datatype::DtFloat(energyOut));
                    return;
                }
                //n+1 mark was detected
                std::chrono::milliseconds rotationTime = std::chrono::duration_cast<std::chrono::milliseconds>(current - this->vLast.value());

                if(rotationTime > this->vThreshold) {
                    if((this->vLast.value() + this->vTimeWindow) >= current) {
                        //time window during
                        energyCol = Core::Type::Datatype::DtFloat(energyCol.toFloat() + (1.0f / static_cast<float>(this->vRotationPerKWh)));
                        vProcessState = Core::Operator::OperatorProcessState::BREAK;
                    } else {
                        //time window exit
                        energyOut = energyCol;
                        this->vLast = current;
                        energyCol = Core::Type::Datatype::DtFloat(1.0f / static_cast<float>(this->vRotationPerKWh));
                        vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                    }
                } else {
                    //ignore value, because of the threshold, that was not passed
                    vProcessState = Core::Operator::OperatorProcessState::BREAK;
                }
            } else {
                //first time a mark was detected; time window entry
                this->vLast = current;
                energyCol = Core::Type::Datatype::DtFloat(1.0f / static_cast<float>(this->vRotationPerKWh));
                vProcessState = Core::Operator::OperatorProcessState::BREAK;
            }

            outputTuple.clear();
            outputTuple.addItem(std::string("energy"),Core::Type::Datatype::DtFloat(energyOut));
        }
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP
