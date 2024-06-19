//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP

#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"

namespace Apalinea::Operator::PipeOperator {
    template<typename Enricher>
    class EnrichPipeOperator
            : public Core::Operator::AbstractPipeOperator{
    public:
        explicit EnrichPipeOperator() : vEnricher() {
        }

        explicit EnrichPipeOperator(EnrichPipeOperator&& other) noexcept
                : vEnricher(std::move(other.vEnricher)) {
        }

        explicit EnrichPipeOperator(EnrichPipeOperator& other) noexcept
                : vEnricher(other.vEnricher) {
        }

        ~EnrichPipeOperator() = default;

        Enricher& getEnricher() {
            return this->vEnricher;
        }

    private:
        Enricher vEnricher;
    protected:
        void work(Core::Tuple::Tuple &inputTuple,
                  Core::Tuple::Tuple& outputTuple) override {
            try {
                if(vEnricher.work(inputTuple,outputTuple)) {
                    vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                } else {
                    vProcessState = Core::Operator::OperatorProcessState::BREAK;
                }
            } catch (std::exception& e) {
                vProcessState = Core::Operator::OperatorProcessState::STOP;
            }
        }
    };
}

#endif // STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP
