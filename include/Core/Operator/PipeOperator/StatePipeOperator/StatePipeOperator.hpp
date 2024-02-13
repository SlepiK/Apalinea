//
// Created by SlepiK on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP

#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Tuple/Tuple.hpp"
#include <utility>

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    class StatePipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator<Energyleaf::Stream::V1::Tuple::Tuple<bool,std::string>,
                    Energyleaf::Stream::V1::Tuple::Tuple<bool,std::string>>{
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
        void work(Energyleaf::Stream::V1::Tuple::Tuple<bool,std::string> &inputTuple,
                  Energyleaf::Stream::V1::Tuple::Tuple<bool,std::string> &outputTuple) override {
            bool input = inputTuple.getItem<bool>(1).getData();
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
                outputTuple.addItem(inputTuple.getItem<std::string>(0));
                outputTuple.addItem(std::string("State"),output);
            } else {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::STOP;
            }
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP
