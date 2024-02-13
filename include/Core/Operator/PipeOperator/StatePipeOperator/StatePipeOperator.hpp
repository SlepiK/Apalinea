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
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator<Energyleaf::Stream::V1::Tuple::Tuple<bool>,
            Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Empty>>{
    public:
        void setState(bool&& state) {
            if(!this->vReady) {
                this->vState = state;
                this->vReady = true;
            }
        }

        [[nodiscard]] const bool& getState() const {
            return this->vState;
        }
    private:
        bool vState;
        bool vReady = false;
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<bool> &inputTuple,
                  Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Empty> &outputTuple) override {
            bool input = inputTuple.getItem<bool>(0).getData();
            bool output;
            if(this->vReady) {
                output = (this->vState != input) && input;
                if(output) this->vState = input;
            } else {
                this->vState = input;
                output = input;
                this->vReady = true;
            }
            if(output){
            outputTuple.clear();
            outputTuple.addItem(std::string("State"),Energyleaf::Stream::V1::Types::Empty());
            } else {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::STOP;
            }
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP
