//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATOR_ABSTRACTSENDER_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATOR_ABSTRACTSENDER_HPP

#include <Operator/SinkOperator/AbstractSinkOperator.hpp>

namespace Energyleaf::Stream::V1::Core::Operator::SinkOperator {
    class AbstractSender {
    public:
        AbstractSender() = default;
        ~AbstractSender() = default;
        virtual bool work(Tuple::Tuple &inputTuple) = 0;
    private:
    protected:
    };
} // STREAM_V1_CORE_OPERATOR_SINKOPERATOR_ABSTRACTSENDER_HPP

#endif
