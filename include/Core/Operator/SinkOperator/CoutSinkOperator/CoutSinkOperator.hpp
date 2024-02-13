//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP

#include <Core/Operator/SinkOperator/WriteSinkOperator/WriteSinkOperator.hpp>
#include <Core/Operator/SinkOperator/CoutSinkOperator/ConsoleWriter.hpp>
#include "Tuple/Tuple.hpp"
#include <iostream>

namespace Energyleaf::Stream::V1::Core::Operator::SinkOperator {
    using CoutSinkOperator = WriteSinkOperator<ConsoleWriter>;
} // Energyleaf::Stream::V1::Core::Operator::SinkOperator

#endif //STREAM_V1_CORE_OPERATOR_SINKOPERATOR_COUTSINKOPERATOR_HPP
