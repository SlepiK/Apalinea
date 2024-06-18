//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP

#include <Operator/PipeOperator/AbstractPipeOperator.hpp>

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    template<typename Enricher>
    class EnrichPipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator{
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

        //ToDo: not every Enrich needs to be processed in main
        [[nodiscard]] Energyleaf::Stream::V1::Operator::OperatorMode getOperatorMode() const override {
            return Energyleaf::Stream::V1::Operator::OperatorMode::MAIN;
        }
    private:
        Enricher vEnricher;
    protected:
        void work(Tuple::Tuple &inputTuple,
                  Tuple::Tuple& outputTuple) override {
            try {
                if(vEnricher.work(inputTuple,outputTuple)) {
                    vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::CONTINUE;
                } else {
                    vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::BREAK;
                }
            } catch (std::exception& e) {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::STOP;
            }
        }
    };
}

#endif // STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP
