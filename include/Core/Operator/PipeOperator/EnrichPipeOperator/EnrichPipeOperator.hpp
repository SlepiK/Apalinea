//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP

#include <Operator/PipeOperator/AbstractPipeOperator.hpp>

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    template<typename Enricher>
    class EnrichPipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator<Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image>,
                    Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image,std::string>>{
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
        void work(Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image> &inputTuple,
                  Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image,std::string>& outputTuple) override {
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
