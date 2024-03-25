//
// Created by SlepiK on 22.03.24.
//

#ifndef STREAM_V1_EXPRESSION_CALULCATION_CALCULATIONEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_CALULCATION_CALCULATIONEXPRESSION_HPP

#include "Expression/Expression.hpp"
#include "Types/Datatype/DtRegistry.hpp"
#include "Types/Datatype/DtInt.hpp"
#include "Types/Datatype/DtInt8.hpp"
#include "Types/Datatype/DtInt16.hpp"
#include "Types/Datatype/DtInt32.hpp"
#include "Types/Datatype/DtInt64.hpp"
#include "Types/Datatype/DtUInt8.hpp"
#include "Types/Datatype/DtUInt16.hpp"
#include "Types/Datatype/DtUInt32.hpp"
#include "Types/Datatype/DtUInt64.hpp"
#include "Types/Datatype/DtSizeT.hpp"
#include "Types/Datatype/DtNumbers.hpp"

namespace Energyleaf::Stream::V1::Expression::Calculation {

    enum class CalculationTypes {
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        MODULO,
        POWER
    };

    class CalculationExpression : public Expression {
    public:
        static constexpr std::string_view IDENTIFIER = Types::Datatype::UNDEFINED;

        CalculationExpression() : Expression({Types::Datatype::DtInt8::IDENTIFIER,Types::Datatype::DtInt16::IDENTIFIER,Types::Datatype::DtInt32::IDENTIFIER,
                                          Types::Datatype::DtInt64::IDENTIFIER,Types::Datatype::DtUInt8::IDENTIFIER,
                                          Types::Datatype::DtUInt16::IDENTIFIER,Types::Datatype::DtUInt32::IDENTIFIER,
                                          Types::Datatype::DtUInt64::IDENTIFIER, Types::Datatype::DtInt::IDENTIFIER,
                                          Types::Datatype::DtSizeT::IDENTIFIER}) {
        }

        void execute() override {
            //Strings are not allowed.
            //We can use normal calculation forms, but we need to respect the used types.
            //If same type, then no problem, if different types, it will be funny.
            //different types mean checking if possible and use the greatest type of them to return the data,
            //or if one of them is float or double force to use one of them as return.
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

        [[nodiscard]] const Types::Datatype::IDt& getData() const override {
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
        Types::Datatype::IDt* data;
        CalculationTypes calculationType;
        IExpression *first, *second;
    };
}

#endif //STREAM_V1_EXPRESSION_CALULCATION_CALCULATIONEXPRESSION_HPP
