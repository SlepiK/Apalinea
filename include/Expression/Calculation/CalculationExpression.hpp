#ifndef APALINEA_EXPRESSION_CALULCATION_CALCULATIONEXPRESSION_HPP
#define APALINEA_EXPRESSION_CALULCATION_CALCULATIONEXPRESSION_HPP

#include "Core/Type/Datatype/DtRegistry.hpp"
#include "Core/Type/Datatype/DtInt.hpp"
#include "Core/Type/Datatype/DtInt8.hpp"
#include "Core/Type/Datatype/DtInt16.hpp"
#include "Core/Type/Datatype/DtInt32.hpp"
#include "Core/Type/Datatype/DtInt64.hpp"
#include "Core/Type/Datatype/DtUInt8.hpp"
#include "Core/Type/Datatype/DtUInt16.hpp"
#include "Core/Type/Datatype/DtUInt32.hpp"
#include "Core/Type/Datatype/DtUInt64.hpp"
#include "Core/Type/Datatype/DtSizeT.hpp"
#include "Core/Type/Datatype/DtNumbers.hpp"
#include "Expression/AbstractExpression.hpp"

namespace Apalinea::Expression::Calculation {

    enum class CalculationTypes {
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        MODULO,
        POWER
    };

    class CalculationExpression : public AbstractExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Type::Datatype::UNDEFINED;

        CalculationExpression() : AbstractExpression({Core::Type::Datatype::DtInt8::IDENTIFIER, Core::Type::Datatype::DtInt16::IDENTIFIER, Core::Type::Datatype::DtInt32::IDENTIFIER,
                                                      Core::Type::Datatype::DtInt64::IDENTIFIER, Core::Type::Datatype::DtUInt8::IDENTIFIER,
                                                      Core::Type::Datatype::DtUInt16::IDENTIFIER, Core::Type::Datatype::DtUInt32::IDENTIFIER,
                                                      Core::Type::Datatype::DtUInt64::IDENTIFIER, Core::Type::Datatype::DtInt::IDENTIFIER,
                                                      Core::Type::Datatype::DtSizeT::IDENTIFIER}) {
        }

        void execute() override {
            if(first == nullptr && second == nullptr) {
                if(vSubExpressions.size() != 2) {
                    throw std::runtime_error("A expression for a single sub expression, cant be executed on less or more then two sub-expression!");
                }
                if(vSubExpressions.empty()) {
                    throw std::runtime_error("A expression can be empty!");
                }

                first = this->vSubExpressions.front();
                this->vSubExpressions.pop_front();
                second = this->vSubExpressions.front();
                this->vSubExpressions.pop_front();

                if(!this->isDatatypeAllowed(first->getIdentifier()) || !this->isDatatypeAllowed(second->getIdentifier())) {
                    throw std::runtime_error("The datatype returned from one of the given expressions is not allowed!");
                }
            }

            first->execute();
            second->execute();

            switch (this->calculationType) {
                case CalculationTypes::ADDITION:
                    this->data = first->getData() + second->getData();
                    break;
                case CalculationTypes::SUBTRACTION:
                    this->data = first->getData() - second->getData();
                    break;
                case CalculationTypes::MULTIPLICATION:
                    this->data = first->getData() * second->getData();
                    break;
                case CalculationTypes::DIVISION:
                    this->data = first->getData() / second->getData();
                    break;
                case CalculationTypes::MODULO:
                    this->data = first->getData() % second->getData();
                    break;
                case CalculationTypes::POWER:
                    this->data = first->getData() ^ second->getData();
                    break;
                default:
                    this->data = first->getData().copy().get();
                    break;
            }

        }

        void setTuple(Core::Tuple::Tuple& tuple) override {
            if(first == nullptr && second == nullptr) {
                for (IExpression *exp: vSubExpressions) {
                    exp->setTuple(tuple);
                }
            } else {
                first->setTuple(tuple);
                second->setTuple(tuple);
            }
        }

        [[nodiscard]] const Core::Type::Datatype::IDt& getData() const override {
            return *this->data;
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }

        void setCalculationType(CalculationTypes type) {
            this->calculationType = type;
        }

        CalculationTypes getCalculationType() {
            return this->calculationType;
        }

    private:
        Core::Type::Datatype::IDt* data;
        CalculationTypes calculationType;
        IExpression *first, *second;
    };
} // Apalinea::Expression::Calculation

#endif //APALINEA_EXPRESSION_CALULCATION_CALCULATIONEXPRESSION_HPP
