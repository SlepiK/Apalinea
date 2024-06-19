//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP

#include <iostream>
#include "Core/Tuple/Tuple.hpp"
#include "Operator/SinkOperator/WriteSinkOperator/WriteSinkOperator.hpp"
#include "Operator/SinkOperator/CoutSinkOperator/ConsoleWriter.hpp"

namespace Apalinea::Operator::SinkOperator {
    using CoutSinkOperator = WriteSinkOperator<ConsoleWriter>;
} // Energyleaf::Stream::V1::Core::Operator::SinkOperator

#endif //STREAM_V1_CORE_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP
