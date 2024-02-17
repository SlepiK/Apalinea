//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ABSTRACTENRICHER_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ABSTRACTENRICHER_HPP

#include <Operator/PipeOperator/AbstractPipeOperator.hpp>

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    class AbstractEnricher {
    public:
        AbstractEnricher() = default;
        ~AbstractEnricher() = default;
        virtual bool work(Tuple::Tuple &inputTuple, Tuple::Tuple& outputTuple) = 0;
    private:
    protected:
    };
} // STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ABSTRACTENRICHER_HPP

#endif
