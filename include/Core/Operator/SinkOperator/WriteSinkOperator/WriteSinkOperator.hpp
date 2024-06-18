//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP

#include <Operator/SinkOperator/AbstractSinkOperator.hpp>
#include <ostream>
#include <Tuple/Tuple.hpp>

#include <Types/Datatype/DtRegistry.hpp>
#include "Types/Datatype/DtString.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::SinkOperator {
    template<typename Writer>
    class WriteSinkOperator
            : public Energyleaf::Stream::V1::Operator::AbstractSinkOperator{
    public:
        explicit WriteSinkOperator() : vWriter() {
        }

        WriteSinkOperator(WriteSinkOperator&& other) noexcept
                : vWriter(std::move(other.vWriter)) {
        }

        WriteSinkOperator(WriteSinkOperator& other) noexcept
                : vWriter(other.vWriter) {
        }

        ~WriteSinkOperator() override {
            if(this->expression != nullptr) {
                delete this->expression;
                this->expression = nullptr;
            }
        }

        [[nodiscard]] Energyleaf::Stream::V1::Operator::OperatorMode getOperatorMode() const override {
            return Energyleaf::Stream::V1::Operator::OperatorMode::DIRECT;
        }

        Writer& getWriter() {
            return this->vWriter;
        }
    private:
        Writer vWriter;
    protected:
        void work(Tuple::Tuple &inputTuple) override {
            try {
                if (this->expression) {
                    this->expression->setTuple(inputTuple);
                    this->expression->execute();
                    if (Types::Datatype::DtRegistry::get(this->expression->getIdentifier()) ==
                        Types::Datatype::DtRegistry::get(Types::Datatype::DtString::IDENTIFIER)) {
                        vWriter
                                << static_cast<const Types::Datatype::DtString &>(this->expression->getData()).toString()
                                << std::endl;
                    }
                    vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::CONTINUE;
                } else {
                    throw std::runtime_error("No expression was used!");
                }
            } catch (const std::exception& e) {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::STOP;
            }
            inputTuple.clear();
        }
    };
}

#endif
