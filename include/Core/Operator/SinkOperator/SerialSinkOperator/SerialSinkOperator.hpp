//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATOR_SERIALSINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATOR_SERIALSINKOPERATOR_HPP

#include "Operator/SinkOperator/AbstractSinkOperator.hpp"
#include "Tuple/Tuple.hpp"

#ifdef ENERGYLEAF_ESP
#include <HardwareSerial.h>
#endif

namespace Energyleaf::Stream::V1::Core::Operator::SinkOperator {

    class SerialSinkOperator
            : public Energyleaf::Stream::V1::Operator::AbstractSinkOperator<Energyleaf::Stream::V1::Tuple::Tuple<std::string>> {
    public:
    private:
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<std::string> &inputTuple) override {
#ifdef ENERGYLEAF_ESP
            Serial.print("New Tuple: ");
            Serial.println(inputTuple.getItem<std::string>(0).getData().c_str());
#endif
        }
    };

} // Energyleaf::Stream::V1::Core::Operator::SinkOperator

#endif //STREAM_V1_CORE_OPERATOR_SINKOPERATOR_SERIALSINKOPERATOR_HPP
