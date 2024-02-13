//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATOR_SENDERSINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATOR_SENDERSINKOPERATOR_HPP

#include <Operator/SinkOperator/AbstractSinkOperator.hpp>

namespace Energyleaf::Stream::V1::Core::Operator::SinkOperator {
    template<typename Sender>
    class SenderSinkOperator
            : public Energyleaf::Stream::V1::Operator::AbstractSinkOperator<Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Power,std::string>> {
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
        void work(Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Power,std::string> &inputTuple) override {
            try {
                /*if(vSender.work(inputTuple)) {
                    vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::CONTINUE;
                } else {
                    vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::BREAK;
                }*/
            } catch (std::exception& e) {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::STOP;
            }
        }
    };
}

#endif
