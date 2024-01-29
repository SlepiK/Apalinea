//
// Created by SlepiK on 29.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP

#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Types/Empty/EmptyType.hpp"
#include "Types/Power/PowerType.hpp"
#include "Tuple/Tuple.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    class CalculatorPipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator<Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::EmptyType>, Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::PowerType>> {
    public:
        static constexpr float WATT_PER_MILLISECOND = 3600000.0f;
        static constexpr float WATT_PER_SECOND = 3600.0f;
        static constexpr float WATT_PER_MINUTE = 60.0f;
        static constexpr float WATT_PER_HOUR = 1.0f;

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
        unsigned long vLast;
        int vRotationPerKWh = 0;
        bool vRotationPerKWhSet = false;
        float wattPer = WATT_PER_MINUTE;
        Energyleaf::Stream::V1::Types::PowerType power;
        bool vRun = false;

        static unsigned long getCurrentTime() {
#ifdef ENERGYLEAF_ESP
             return millis();
#else
            return 0u;
#endif
         }
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::EmptyType> &inputTuple,
                  Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::PowerType> &outputTuple) override {
            if(!this->vRotationPerKWhSet) {
                throw std::runtime_error("Operator was not configured before use! Config before first use!");
            }
            this->vRun = true;

            if(this->vLast > 0) {
                unsigned long current = getCurrentTime();
                unsigned long rotationTime = current - this->vLast;
                if(rotationTime > 30) {
                    power = (this->wattPer / rotationTime / this->vRotationPerKWh) * 1000.0f;
                    this->vLast = current;
                } else {
                    power = 0.0f;
                }
            } else {
                //initial process, no red mark was detected before this event.
                this->vLast = getCurrentTime();
            }
        }
    };
} // Energyleaf::Stream::V1::Core::Operator::PipeOperator

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_CALCULATORPIPEOPERATOR_HPP
