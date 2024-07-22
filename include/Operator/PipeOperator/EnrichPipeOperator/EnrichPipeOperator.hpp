#ifndef APALINEA_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP
#define APALINEA_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP

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
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR,Core::Log::getFilename(__FILE__),__LINE__,e.what());
                vProcessState = Core::Operator::OperatorProcessState::STOP;
            }
        }
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_ENRICHPIPEOPERATOR_HPP
