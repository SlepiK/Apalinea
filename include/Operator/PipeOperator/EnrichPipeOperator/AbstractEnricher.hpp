#ifndef APALINEA_OPERATOR_PIPEOPERATOR_ABSTRACTENRICHER_HPP
#define APALINEA_OPERATOR_PIPEOPERATOR_ABSTRACTENRICHER_HPP

#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"

namespace Apalinea::Operator::PipeOperator {
    class AbstractEnricher {
    public:
        AbstractEnricher() = default;

        ~AbstractEnricher() = default;

        virtual bool work(Core::Tuple::Tuple &inputTuple, Core::Tuple::Tuple& outputTuple) = 0;
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_ABSTRACTENRICHER_HPP
