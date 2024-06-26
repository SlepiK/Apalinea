#ifndef APALINEA_OPERATOR_PIPEOPERATOR_WINDOWPIPEOPERATOR_HPP
#define APALINEA_OPERATOR_PIPEOPERATOR_WINDOWPIPEOPERATOR_HPP

#include <cstddef>
#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Tuple/Tuple.hpp"

namespace Apalinea::Operator::PipeOperator {
    class [[maybe_unused]] WindowPipeOperator : Core::Operator::AbstractPipeOperator {
    public:
        [[maybe_unused]] void setSize(std::size_t&& size) {
            this->vWindowSize = size;
        }

        [[maybe_unused]] [[nodiscard]] const std::size_t& getSize() const {
            return this->vWindowSize;
        }

        [[maybe_unused]] [[nodiscard]] const std::size_t& getCurrentSize() const {
            return this->vWindowCurrent;
        }

    private:
        std::size_t vWindowCurrent = 0;
        std::size_t vWindowSize = 1;
        std::size_t vWindowSizeActual = 0;

    protected:
        void work(Core::Tuple::Tuple &inputTuple,
                  Core::Tuple::Tuple &outputTuple) override {
            outputTuple.clear();
            if(++this->vWindowSizeActual == this->vWindowSize) {
                this->vWindowSizeActual = 0;
                ++this->vWindowCurrent;
            }
        }
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_WINDOWPIPEOPERATOR_HPP
