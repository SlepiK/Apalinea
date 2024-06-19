//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ABSTRACTENRICHER_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ABSTRACTENRICHER_HPP

#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"

namespace Apalinea::Operator::PipeOperator {
    class AbstractEnricher {
    public:
        AbstractEnricher() = default;
        ~AbstractEnricher() = default;
        virtual bool work(Core::Tuple::Tuple &inputTuple, Core::Tuple::Tuple& outputTuple) = 0;
    private:
    protected:
    };
} // STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ABSTRACTENRICHER_HPP

#endif
