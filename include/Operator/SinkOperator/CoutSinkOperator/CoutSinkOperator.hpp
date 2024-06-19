#ifndef APALINEA_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP
#define APALINEA_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP

#include <iostream>
#include "Core/Tuple/Tuple.hpp"
#include "Operator/SinkOperator/WriteSinkOperator/WriteSinkOperator.hpp"
#include "Operator/SinkOperator/CoutSinkOperator/ConsoleWriter.hpp"

namespace Apalinea::Operator::SinkOperator {
    using CoutSinkOperator = WriteSinkOperator<ConsoleWriter>;
} // Apalinea::Operator::SinkOperator

#endif //APALINEA_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP
