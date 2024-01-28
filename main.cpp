//
// Created by SlepiK on 27.01.2024.
//

#include "Core/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.hpp"
#include "include/Operator/SinkOperator/SinkOperator.hpp"
#include "include/Tuple/Tuple.hpp"

int main(int argc, char *argv[])
{
    Stream::V1::Tuple::Tuple<std::string> text;
    text.addItem(std::string("TestText"),std::string("Was geht"));
    Stream::V1::Core::Operator::SinkOperator::CoutSinkOperator coutSinkOperator;
    coutSinkOperator.process(text);
    coutSinkOperator.process(text);
    coutSinkOperator.process(text);
    coutSinkOperator.process(text);
}