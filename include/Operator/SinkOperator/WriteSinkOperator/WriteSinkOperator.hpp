//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP

#include <ostream>
#include "Core/Operator/SinkOperator/AbstractSinkOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtRegistry.hpp"
#include "Core/Type/Datatype/DtString.hpp"

namespace Apalinea::Operator::SinkOperator {
    template<typename Writer>
    class WriteSinkOperator
            : public Core::Operator::AbstractSinkOperator{
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

        [[nodiscard]] Core::Operator::OperatorMode getOperatorMode() const override {
            return Core::Operator::OperatorMode::DIRECT;
        }

        Writer& getWriter() {
            return this->vWriter;
        }
    private:
        Writer vWriter;
    protected:
        void work(Core::Tuple::Tuple &inputTuple) override {
            try {
                if (this->expression) {
                    this->expression->setTuple(inputTuple);
                    this->expression->execute();
                    if (Core::Types::Datatype::DtRegistry::get(this->expression->getIdentifier()) ==
                            Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtString::IDENTIFIER)) {
                        vWriter
                                << static_cast<const Core::Types::Datatype::DtString &>(this->expression->getData()).toString()
                                << std::endl;
                    }
                    vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                } else {
                    throw std::runtime_error("No expression was used!");
                }
            } catch (const std::exception& e) {
                vProcessState = Core::Operator::OperatorProcessState::STOP;
            }
            inputTuple.clear();
        }
    };
}

#endif
