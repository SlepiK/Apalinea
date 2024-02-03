//
// Created by SlepiK on 29.01.24.
//

#include "Core/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.hpp"
#include "Core/Operator/SourceOperator/StringDemoSourceOperator/StringDemoSourceOperator.hpp"
#include "Core/Operator/PipeOperator/CalculatorPipeOperator/CalculatorPipeOperator.hpp"
#include "Core/Operator/PipeOperator/CropPipeOperator/CropPipeOperator.hpp"
#include "Core/Operator/SinkOperator/WebSenderSinkOperator/WebSenderSinkOperator.hpp"
#include "Core/Operator/PipeOperator/StatePipeOperator/StatePipeOperator.hpp"
#include "Core/Operator/PipeOperator/WindowPipeOperator/WindowPipeOperator.hpp"
#include "Core/Operator/PipeOperator/SelectPipeOperator/SelectPipeOperator.hpp"
#include "Core/Operator/PipeOperator/DetectorPipeOperator/DetectorPipeOperator.hpp"
#include "CameraEL.hpp"
#include "Core/Operator/SourceOperator/CameraSourceOperator/CameraSourceOperator.hpp"

#include "Core/Plan/Plan.hpp"

int main(int argc, char *argv[])
{
    Energyleaf::Stream::V1::Core::Plan::Plan plan;
    auto testr = plan.createLink(Energyleaf::Stream::V1::Link::make_SourceLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SourceOperator::CameraSourceOperator<CameraEL>>());
    testr.get()->getOperator().start();

    auto sourcelink = plan.createLink(Energyleaf::Stream::V1::Link::make_SourceLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SourceOperator::StringDemoSourceOperator>());
    auto pipelink = plan.createLink(Energyleaf::Stream::V1::Link::make_PipeLinkUPtr<Energyleaf::Stream::V1::Core::Operator::PipeOperator::CalculatorPipeOperator>());
    pipelink->getOperator().setCalculationFormat(Energyleaf::Stream::V1::Core::Operator::PipeOperator::CalculatorPipeOperator::CalculationFormat::SECOND);
    pipelink->getOperator().setRotationPerKWh(375);
    auto pipelink2 = plan.createLink(Energyleaf::Stream::V1::Link::make_PipeLinkUPtr<Energyleaf::Stream::V1::Core::Operator::PipeOperator::CropPipeOperator>());
    pipelink2->getOperator().setSize(0,30,0,30);
    auto pipelink3 = plan.createLink(Energyleaf::Stream::V1::Link::make_PipeLinkUPtr<Energyleaf::Stream::V1::Core::Operator::PipeOperator::DetectorPipeOperator>());
    pipelink3->getOperator().setLowerBorder(Energyleaf::Stream::V1::Types::Pixel::HSV(90.f,50.f,70.f));
    pipelink3->getOperator().setHigherBorder(Energyleaf::Stream::V1::Types::Pixel::HSV(128.f,255.f,255.f));
    auto pipelink4 = plan.createLink(Energyleaf::Stream::V1::Link::make_PipeLinkUPtr<Energyleaf::Stream::V1::Core::Operator::PipeOperator::SelectPipeOperator>());
    pipelink4->getOperator().setThreshold(300);
    auto pipelink5 = plan.createLink(Energyleaf::Stream::V1::Link::make_PipeLinkUPtr<Energyleaf::Stream::V1::Core::Operator::PipeOperator::StatePipeOperator>());
    pipelink5->getOperator().setState(false);
    auto sinklink = plan.createLink(Energyleaf::Stream::V1::Link::make_SinkLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SinkOperator::CoutSinkOperator>());
    auto sinklink2 = plan.createLink(Energyleaf::Stream::V1::Link::make_SinkLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SinkOperator::CoutSinkOperator>());
    //auto sinklink2 = plan.createLink(Energyleaf::Stream::V1::Link::make_SinkLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SinkOperator::WebSenderSinkOperator>());
    plan.connect(sourcelink,sinklink);
    plan.connect(sourcelink,sinklink2);
    plan.connect(testr,pipelink2);
    plan.connect(pipelink2,pipelink3);
    plan.connect(pipelink3,pipelink4);
    plan.connect(pipelink4,pipelink5);
    plan.process();
}