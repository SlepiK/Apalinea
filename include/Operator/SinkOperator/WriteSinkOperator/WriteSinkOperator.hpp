#ifndef APALINEA_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP
#define APALINEA_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP

#include <ostream>
#include "Core/Operator/SinkOperator/AbstractSinkOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtRegistry.hpp"
#include "Core/Type/Datatype/DtString.hpp"

namespace Apalinea::Operator::SinkOperator {
    template<typename Writer>
    class WriteSinkOperator
: public Core::Operator::AbstractSinkOperator {
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

        [[maybe_unused]] Writer& getWriter() {
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
                    if (Core::Type::Datatype::DtRegistry::get(this->expression->getIdentifier()) ==
                        Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtString::IDENTIFIER)) {
                        vWriter
                                << static_cast<const Core::Type::Datatype::DtString &>(this->expression->getData()).toString()
                                << std::endl;
                    }
                    vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                } else {
                    throw std::runtime_error("No expression was used!");
                }
            } catch (const std::exception& e) {
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR,Core::Log::getFilename(__FILE__),__LINE__,e.what());
                vProcessState = Core::Operator::OperatorProcessState::STOP;
            }
            inputTuple.clear();
        }
    };
} // Apalinea::Operator::SinkOperator

#endif //APALINEA_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP
