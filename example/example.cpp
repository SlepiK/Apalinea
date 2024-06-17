//
// Created by SlepiK on 29.01.24.
//

#include "Core/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.hpp"
#include "Core/Operator/SourceOperator/StringDemoSourceOperator/StringDemoSourceOperator.hpp"
#include "Core/Plan/Plan.hpp"
#include "Core/Executor/BoostExecutor.hpp"
#include "Core/Executor/STLExecutor.hpp"

#include <Expression/Compare/CompareExpression.hpp>
#include <Expression/ToExpression/ToDtStringExpression.hpp>
#include <Expression/Datatype/DtInt8Expression.hpp>
#include <Expression/Calculation/CalculationExpression.hpp>
#include <Expression/ToExpression/ToDtFloatExpression.hpp>

int main(int argc, char *argv[])
{
    Energyleaf::Stream::V1::Expression::ToDtStringExpression* tse = new Energyleaf::Stream::V1::Expression::ToDtStringExpression();
    Energyleaf::Stream::V1::Expression::DataType::DtInt8Expression *edt = new Energyleaf::Stream::V1::Expression::DataType::DtInt8Expression("DemoString");
    Energyleaf::Stream::V1::Expression::DataType::DtInt8Expression *edtBase = new Energyleaf::Stream::V1::Expression::DataType::DtInt8Expression(2);
    Energyleaf::Stream::V1::Expression::DataType::DtInt8Expression *edtBase2 = new Energyleaf::Stream::V1::Expression::DataType::DtInt8Expression(4);
    Energyleaf::Stream::V1::Expression::Calculation::CalculationExpression *calc = new Energyleaf::Stream::V1::Expression::Calculation::CalculationExpression();
    Energyleaf::Stream::V1::Expression::ToDtFloatExpression* tfe = new Energyleaf::Stream::V1::Expression::ToDtFloatExpression();
    calc->setCalculationType(Energyleaf::Stream::V1::Expression::Calculation::CalculationTypes::DIVISION);
    calc->add(edtBase);
    calc->add(edtBase2);
    Energyleaf::Stream::V1::Expression::Compare::CompareExpression *comp = new Energyleaf::Stream::V1::Expression::Compare::CompareExpression();
    comp->add(edt);
    comp->add(edtBase);
    comp->setCompareType(Energyleaf::Stream::V1::Expression::Compare::CompareTypes::EQUAL);
    tfe->add(calc);
    tse->add(tfe);

    Energyleaf::Stream::V1::Core::Plan::Plan plan(std::make_shared<Energyleaf::Stream::V1::Core::Executor::STLExecutor>(3));
    //auto sourcelink = plan.createLink(Energyleaf::Stream::V1::Link::make_SourceLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SourceOperator::StringDemoSourceOperator>());
    auto sourcelink = plan.createSource<Energyleaf::Stream::V1::Core::Operator::SourceOperator::StringDemoSourceOperator>();
    auto sinklink = plan.createSink<Energyleaf::Stream::V1::Core::Operator::SinkOperator::CoutSinkOperator>();
    sinklink.get()->getOperator().setExpression(tse);
    auto sinklink2 = plan.createSink<Energyleaf::Stream::V1::Core::Operator::SinkOperator::CoutSinkOperator>();
    plan.connect(sourcelink,sinklink);
    plan.connect(sourcelink,sinklink2);
    auto sourcelink2 = plan.createSource<Energyleaf::Stream::V1::Core::Operator::SourceOperator::StringDemoSourceOperator>();
    auto sinklink3 = plan.createSink<Energyleaf::Stream::V1::Core::Operator::SinkOperator::CoutSinkOperator>();
    plan.connect(sourcelink2,sinklink3);
    /*plan.process();
    plan.join();
    plan.process();
    plan.join();
    plan.process();
    plan.join();*/
    plan.order();
    plan.processOrdered();
    plan.join();
    plan.processOrdered();
    plan.join();
}