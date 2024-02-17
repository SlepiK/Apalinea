//
// Created by SlepiK on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_WINDOWPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_WINDOWPIPEOPERATOR_HPP

#include <cstddef>
#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Tuple/Tuple.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    template<typename Input, typename Output>
    class WindowPipeOperator : Energyleaf::Stream::V1::Operator::AbstractPipeOperator {
    public:
        void setSize(std::size_t&& size) {
            this->vWindowSize = size;
        }

        [[nodiscard]] const std::size_t& getSize() const {
            return this->vWindowSize;
        }

        const std::size_t& getCurrentSize() {
            return this->vWindowCurrent;
        }
    private:
        std::size_t vWindowCurrent = 0;
        std::size_t vWindowSize = 1;
        std::size_t vWindowSizeActual = 0;
    protected:
        void work(Tuple::Tuple &inputTuple,
                  Tuple::Tuple &outputTuple) override {
            outputTuple.clear();
            /*outputTuple.addItem(inputTuple);
            outputTuple.addItem(std::string("INTERNAL_WINDOW"),this->vWindowCurrent);*/
            if(++this->vWindowSizeActual == this->vWindowSize) {
                this->vWindowSizeActual = 0;
                ++this->vWindowCurrent;
            }
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_WINDOWPIPEOPERATOR_HPP
