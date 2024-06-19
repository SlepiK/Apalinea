//
// Created by SlepiK on 29.01.24.
//

#include "Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.hpp"
#include "Operator/SourceOperator/StringDemoSourceOperator/StringDemoSourceOperator.hpp"
#include "Core/Plan/Plan.hpp"
#include "Core/Executor/STLExecutor.hpp"
#include "Core/Log/LogManager.hpp"
#include "Core/Log/ConsoleLog.hpp"

#include "Expression/Compare/CompareExpression.hpp"
#include "Expression/ToExpression/ToDtStringExpression.hpp"
#include "Expression/Datatype/DtInt8Expression.hpp"
#include "Expression/Calculation/CalculationExpression.hpp"
#include "Expression/ToExpression/ToDtFloatExpression.hpp"

int main(int argc, char *argv[])
{
    Apalinea::Core::Log::LogManager::addLog(std::make_unique<Apalinea::Core::Log::ConsoleLog>());
    Apalinea::Expression::ToDtStringExpression* tse = new Apalinea::Expression::ToDtStringExpression();
    Apalinea::Expression::DataType::DtInt8Expression *edt = new Apalinea::Expression::DataType::DtInt8Expression("DemoString");
    Apalinea::Expression::DataType::DtInt8Expression *edtBase = new Apalinea::Expression::DataType::DtInt8Expression(2);
    Apalinea::Expression::DataType::DtInt8Expression *edtBase2 = new Apalinea::Expression::DataType::DtInt8Expression(4);
    Apalinea::Expression::Calculation::CalculationExpression *calc = new Apalinea::Expression::Calculation::CalculationExpression();
    Apalinea::Expression::ToDtFloatExpression* tfe = new Apalinea::Expression::ToDtFloatExpression();
    calc->setCalculationType(Apalinea::Expression::Calculation::CalculationTypes::DIVISION);
    calc->add(edtBase);
    calc->add(edtBase2);
    Apalinea::Expression::Compare::CompareExpression *comp = new Apalinea::Expression::Compare::CompareExpression();
    comp->add(edt);
    comp->add(edtBase);
    comp->setCompareType(Apalinea::Expression::Compare::CompareTypes::EQUAL);
    tfe->add(calc);
    tse->add(tfe);

    Apalinea::Core::Plan::Plan plan(std::make_shared<Apalinea::Core::Executor::STLExecutor>(3));
    //auto sourcelink = plan.createLink(Energyleaf::Stream::V1::Link::make_SourceLinkUPtr<Energyleaf::Stream::V1::Core::Operator::SourceOperator::StringDemoSourceOperator>());
    auto sourcelink = plan.createSource<Apalinea::Operator::SourceOperator::StringDemoSourceOperator>();
    auto sinklink = plan.createSink<Apalinea::Operator::SinkOperator::CoutSinkOperator>();
    sinklink.get()->getOperator().setExpression(tse);
    auto sinklink2 = plan.createSink<Apalinea::Operator::SinkOperator::CoutSinkOperator>();
    plan.connect(sourcelink,sinklink);
    plan.connect(sourcelink,sinklink2);
    auto sourcelink2 = plan.createSource<Apalinea::Operator::SourceOperator::StringDemoSourceOperator>();
    auto sinklink3 = plan.createSink<Apalinea::Operator::SinkOperator::CoutSinkOperator>();
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