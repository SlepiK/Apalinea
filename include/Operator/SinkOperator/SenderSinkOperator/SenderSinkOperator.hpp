#ifndef APALINEA_OPERATOR_SINKOPERATOR_SENDERSINKOPERATOR_HPP
#define APALINEA_OPERATOR_SINKOPERATOR_SENDERSINKOPERATOR_HPP

#include "Core/Operator/SinkOperator/AbstractSinkOperator.hpp"

namespace Apalinea::Operator::SinkOperator {
    template<typename Sender>
    class SenderSinkOperator
            : public Core::Operator::AbstractSinkOperator {
    public:
        explicit SenderSinkOperator() : vSender() {
        }

        explicit SenderSinkOperator(SenderSinkOperator&& other) noexcept
                : vSender(std::move(other.vSender)) {
        }

        explicit SenderSinkOperator(SenderSinkOperator& other) noexcept
                : vSender(other.vSender) {
        }

        ~SenderSinkOperator() = default;

        Sender& getSender() {
            return this->vSender;
        }

    private:
        Sender vSender;

    protected:
        void work(Core::Tuple::Tuple &inputTuple) override {
            try {
                if(vSender.work(inputTuple)) {
                    vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                } else {
                    vProcessState = Core::Operator::OperatorProcessState::BREAK;
                }
            } catch (std::exception& e) {
                vProcessState = Core::Operator::OperatorProcessState::STOP;
            }
            inputTuple.clear();
        }
    };
} // Apalinea::Operator::SinkOperator

#endif //APALINEA_OPERATOR_SINKOPERATOR_SENDERSINKOPERATOR_HPP
