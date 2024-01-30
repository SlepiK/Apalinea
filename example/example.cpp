//
// Created by SlepiK on 29.01.24.
//

#include "Core/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.hpp"
#include "Core/Operator/SourceOperator/StringDemoSourceOperator/StringDemoSourceOperator.hpp"
#include "Core/Operator/PipeOperator/CalculatorPipeOperator/CalculatorPipeOperator.hpp"
#include "Core/Operator/PipeOperator/CropPipeOperator/CropPipeOperator.hpp"

#include "Core/Plan/Plan.hpp"

int main(int argc, char *argv[])
{
    Energyleaf::Stream::V1::Core::Plan::Plan plan;
    auto sourcelink = plan.createLink(Energyleaf::Stream::V1::Link::make_SourceLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SourceOperator::StringDemoSourceOperator>());
    auto pipelink = plan.createLink(Energyleaf::Stream::V1::Link::make_PipeLinkUPtr<Energyleaf::Stream::V1::Core::Operator::PipeOperator::CalculatorPipeOperator>());
    pipelink->getOperator().setCalculationFormat(Energyleaf::Stream::V1::Core::Operator::PipeOperator::CalculatorPipeOperator::CalculationFormat::SECOND);
    pipelink->getOperator().setRotationPerKWh(375);
    auto pipelink2 = plan.createLink(Energyleaf::Stream::V1::Link::make_PipeLinkUPtr<Energyleaf::Stream::V1::Core::Operator::PipeOperator::CropPipeOperator>());
    auto sinklink = plan.createLink(Energyleaf::Stream::V1::Link::make_SinkLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SinkOperator::CoutSinkOperator>());
    plan.connect(sourcelink,sinklink);
    plan.process();
}