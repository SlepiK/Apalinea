//
// Created by SlepiK on 29.01.24.
//

#include "Core/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.hpp"
#include "Core/Operator/SourceOperator/StringDemoSourceOperator/StringDemoSourceOperator.hpp"

#include "Core/Plan/Plan.hpp"

int main(int argc, char *argv[])
{
    Energyleaf::Stream::V1::Core::Plan::Plan plan;
    auto sourcelink = plan.createLink(Energyleaf::Stream::V1::Link::make_SourceLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SourceOperator::StringDemoSourceOperator>());
    auto sinklink = plan.createLink(Energyleaf::Stream::V1::Link::make_SinkLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SinkOperator::CoutSinkOperator>());
    plan.connect(sourcelink,sinklink);
    plan.process();
}