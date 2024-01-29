//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP

#include "Operator/SinkOperator/AbstractSinkOperator.hpp"
#include "Tuple/Tuple.hpp"
#include <iostream>

namespace Energyleaf::Stream::V1::Core::Operator::SinkOperator {

    class CoutSinkOperator : public Energyleaf::Stream::V1::Operator::AbstractSinkOperator<Energyleaf::Stream::V1::Tuple::Tuple<std::string>> {
    public:
    private:
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<std::string> &inputTuple) override {
            std::cout << "New Tuple: " << inputTuple.getItem<std::string>(0).getData() << std::endl;
        }
    };

} // Stream::V1::Core::Operator::AbstractSinkOperator

#endif //STREAM_V1_CORE_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP
