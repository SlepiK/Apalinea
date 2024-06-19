#ifndef APALINEA_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP
#define APALINEA_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP

#include <utility>
#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtBool.hpp"

namespace Apalinea::Operator::PipeOperator {
    class StatePipeOperator
            : public Core::Operator::AbstractPipeOperator {
    public:
        void setState(bool&& state) {
            if(!this->vReady) {
                this->vState = state;
            }
        }

        [[nodiscard]] const bool& getState() const {
            return this->vState;
        }

    private:
        bool vState;
        bool vReady = false;

    protected:
        void work(Core::Tuple::Tuple &inputTuple,
                  Core::Tuple::Tuple &outputTuple) override {
            if(!inputTuple.containsItem("Select")){
                vProcessState = Core::Operator::OperatorProcessState::BREAK;
                return;
            } else {
                vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
            }
            bool input = inputTuple.getItem<Core::Type::Datatype::DtBool>("Select").toBool();
            inputTuple.removeItem("Select");
            bool output;
            if(this->vReady) {
                bool tmp = (this->vState != input);
                output = tmp && input;
                if(tmp) this->vState = input;
            } else {
                this->vState = input;
                output = input;
                this->vReady = true;
            }

            if(output){
                vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                outputTuple.clear();
                outputTuple.moveItems(std::move(inputTuple));
                outputTuple.addItem(std::string("State"),Core::Type::Datatype::DtBool(output));
            } else {
                vProcessState = Core::Operator::OperatorProcessState::BREAK;
            }
        }
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP
