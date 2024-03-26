//
// Created by SlepiK on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP

#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Tuple/Tuple.hpp"

#include "Types/Datatype/DtBool.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    class SelectPipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator {
    public:
        void setThreshold(int&& threshold) {
            this->vThreshold = threshold;
        }

        [[nodiscard]] const int& getThreshold() const {
            return this->vThreshold;
        }
    private:
        int vThreshold = 0;
    protected:
        void work(Tuple::Tuple &inputTuple,
                  Tuple::Tuple &outputTuple) override {
            std::size_t input = 0;// inputTuple.getItem<std::size_t>(1).getData();
            bool select = input > this->vThreshold;
            outputTuple.clear();
            /*outputTuple.addItem(inputTuple.getItem<std::string>(0));
            outputTuple.addItem(std::string("SELECT"), select);*/

            try {
                if (this->expression) {
                    this->expression->setTuple(inputTuple);
                    this->expression->execute();
                    if (Types::Datatype::DtRegistry::get(this->expression->getIdentifier()) ==
                        Types::Datatype::DtRegistry::get(Types::Datatype::DtBool::IDENTIFIER)) {

                        bool eval = static_cast<const Types::Datatype::DtBool&>(this->expression->getData()).toBool();
                        outputTuple.clear();
                        if(eval) {
                            outputTuple.addItem(std::string("SELECT"),Types::Datatype::DtBool(eval));
                            vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::CONTINUE;
                        } else {
                            vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::BREAK;
                        }
                    } else {
                        vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::BREAK;
                    }
                } else {
                    throw std::runtime_error("No expression was used!");
                }
            } catch (const std::exception& e) {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::STOP;
            }
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP
