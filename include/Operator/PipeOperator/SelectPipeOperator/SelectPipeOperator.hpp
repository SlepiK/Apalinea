//
// Created by SlepiK on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP

#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtBool.hpp"

namespace Apalinea::Operator::PipeOperator {
    class SelectPipeOperator
            : public Core::Operator::AbstractPipeOperator {
    public:
    private:
    protected:
        void work(Core::Tuple::Tuple &inputTuple,
                  Core::Tuple::Tuple &outputTuple) override {

            try {
                if (this->expression) {
                    this->expression->setTuple(inputTuple);
                    this->expression->execute();
                    if (Core::Types::Datatype::DtRegistry::get(this->expression->getIdentifier()) ==
                            Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtBool::IDENTIFIER)) {

                        bool eval = static_cast<const Core::Types::Datatype::DtBool&>(this->expression->getData()).toBool();

                        outputTuple.clear();
                        outputTuple.moveItems(std::move(inputTuple));
                        outputTuple.addItem(std::string("Select"),Core::Types::Datatype::DtBool(eval));
                        vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                    } else {
                        vProcessState = Core::Operator::OperatorProcessState::BREAK;
                    }
                } else {
                    throw std::runtime_error("No expression was used!");
                }
            } catch (const std::exception& e) {
                vProcessState = Core::Operator::OperatorProcessState::STOP;
            }
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP
