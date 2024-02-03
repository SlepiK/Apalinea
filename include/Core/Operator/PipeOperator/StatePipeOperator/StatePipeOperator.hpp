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
            Energyleaf::Stream::V1::Tuple::Tuple<bool>>{
    public:
        void setState(bool&& state) {
            this->vState = state;
        }

        [[nodiscard]] const bool& getState() const {
            return this->vState;
        }
    private:
        bool vState;
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<bool> &inputTuple,
                  Energyleaf::Stream::V1::Tuple::Tuple<bool> &outputTuple) override {
            bool input = inputTuple.getItem<bool>(0).getData();
            bool output;
            if (this->vState != input) {
                this->vState = input;
                output = true;
            } else {
                output = false;
            }
            outputTuple.clear();
            outputTuple.addItem(std::string("ProcessState"),output);
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_STATEPIPEOPERATOR_HPP
