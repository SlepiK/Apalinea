//
// Created by Simon Stahmer on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP

#include <Operator/SinkOperator/AbstractSinkOperator.hpp>
#include <ostream>
#include <Tuple/Tuple.hpp>

namespace Energyleaf::Stream::V1::Core::Operator::SinkOperator {
    template<typename Writer>
    class WriteSinkOperator
            : public Energyleaf::Stream::V1::Operator::AbstractSinkOperator<Energyleaf::Stream::V1::Tuple::Tuple<std::string>>{
    public:
        explicit WriteSinkOperator() : vWriter() {
        }

        explicit WriteSinkOperator(WriteSinkOperator&& other) noexcept
                : vWriter(std::move(other.vWriter)) {
        }

        explicit WriteSinkOperator(WriteSinkOperator& other) noexcept
                : vWriter(other.vWriter) {
        }

        ~WriteSinkOperator() = default;

        Writer& getWriter() {
            return this->vWriter;
        }
    private:
        Writer vWriter;
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<std::string> &inputTuple) override {
            try {
                vWriter << inputTuple.getItem<std::string>(0).getData() << std::endl;
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::CONTINUE;
            } catch (std::exception& e) {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::STOP;
            }
        }
    };
}

#endif
