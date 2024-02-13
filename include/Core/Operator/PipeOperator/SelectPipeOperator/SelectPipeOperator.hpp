//
// Created by SlepiK on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP

#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Tuple/Tuple.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    class SelectPipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator<Energyleaf::Stream::V1::Tuple::Tuple<std::size_t,std::string>,
                    Energyleaf::Stream::V1::Tuple::Tuple<bool,std::string>> {
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
        void work(Energyleaf::Stream::V1::Tuple::Tuple<std::size_t,std::string> &inputTuple,
                  Energyleaf::Stream::V1::Tuple::Tuple<bool,std::string> &outputTuple) override {
            std::size_t input = inputTuple.getItem<std::size_t>(1).getData();
            bool select = input > this->vThreshold;
            outputTuple.clear();
            outputTuple.addItem(inputTuple.getItem<std::string>(0));
            outputTuple.addItem(std::string("SELECT"), select);
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP
