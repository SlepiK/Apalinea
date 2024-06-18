//
// Created by SlepiK on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP

#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Tuple/Tuple.hpp"
#include <utility>
#include "Types/Datatype/DtBool.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    class StatePipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator {
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
        void work(Tuple::Tuple &inputTuple,
                  Tuple::Tuple &outputTuple) override {
            if(!inputTuple.containsItem("Select")){
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::BREAK;
                return;
            } else {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::CONTINUE;
            }
            bool input = inputTuple.getItem<Types::Datatype::DtBool>("Select").toBool();
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
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::CONTINUE;
                outputTuple.clear();
                outputTuple.moveItems(std::move(inputTuple));
                outputTuple.addItem(std::string("State"),Types::Datatype::DtBool(output));
            } else {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::BREAK;
            }
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP
