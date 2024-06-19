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

int main()
{
    Apalinea::Core::Log::LogManager::addLog(std::make_unique<Apalinea::Core::Log::ConsoleLog>());
    auto* tse = new Apalinea::Expression::ToDtStringExpression();
    auto *edt = new Apalinea::Expression::DataType::DtInt8Expression("DemoString");
    auto *edtBase = new Apalinea::Expression::DataType::DtInt8Expression(2);
    auto *edtBase2 = new Apalinea::Expression::DataType::DtInt8Expression(4);
    auto *calc = new Apalinea::Expression::Calculation::CalculationExpression();
    auto* tfe = new Apalinea::Expression::ToDtFloatExpression();
    calc->setCalculationType(Apalinea::Expression::Calculation::CalculationTypes::DIVISION);
    calc->add(edtBase);
    calc->add(edtBase2);
    auto *comp = new Apalinea::Expression::Compare::CompareExpression();
    comp->add(edt);
    comp->add(edtBase);
    comp->setCompareType(Apalinea::Expression::Compare::CompareTypes::EQUAL);
    tfe->add(calc);
    tse->add(tfe);

    Apalinea::Core::Plan::Plan plan(std::make_shared<Apalinea::Core::Executor::STLExecutor>(3));
    auto demoSource = plan.createSource<Apalinea::Operator::SourceOperator::StringDemoSourceOperator>();
    auto demoCoutSink = plan.createSink<Apalinea::Operator::SinkOperator::CoutSinkOperator>();
    demoCoutSink.get()->getOperator().setExpression(tse);
    auto DemoCoutSinkNOP = plan.createSink<Apalinea::Operator::SinkOperator::CoutSinkOperator>();
    plan.connect(demoSource, demoCoutSink);
    plan.connect(demoSource, DemoCoutSinkNOP);
    plan.order();
    plan.processOrdered();
    plan.join();
    plan.processOrdered();
    plan.join();
}