//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATOR_ABSTRACTSENDER_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATOR_ABSTRACTSENDER_HPP

#include "Core/Operator/SinkOperator/AbstractSinkOperator.hpp"

namespace Apalinea::Operator::SinkOperator {
    class AbstractSender {
    public:
        AbstractSender() = default;
        ~AbstractSender() = default;
        virtual bool work(Core::Tuple::Tuple &inputTuple) = 0;
    private:
    protected:
    };
} // STREAM_V1_CORE_OPERATOR_SINKOPERATOR_ABSTRACTSENDER_HPP

#endif
