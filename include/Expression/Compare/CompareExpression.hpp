//
// Created by SlepiK on 19.03.24.
//

#ifndef STREAM_V1_EXPRESSION_COMPARE_COMPAREEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_COMPARE_COMPAREEXPRESSION_HPP

#include "Core/Type/Datatype/DtBool.hpp"
#include "Core/Type/Datatype/DtString.hpp"
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
#include "Expression/AbstractExpression.hpp"

namespace Apalinea::Expression::Compare {
    //A > #
    //# < A
    //A > B
    //A == B
    //A == #

    enum class CompareTypes {
        EQUAL,
        NOT_EQUAL,
        LESS_THAN,
        GREATER_THAN,
        LESS_THAN_OR_EQUAL,
        GREATER_THAN_OR_EQUAL
    };

    class CompareExpression : public AbstractExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Types::Datatype::DtBool::IDENTIFIER;

        CompareExpression() : AbstractExpression({Core::Types::Datatype::DtInt8::IDENTIFIER, Core::Types::Datatype::DtInt16::IDENTIFIER, Core::Types::Datatype::DtInt32::IDENTIFIER,
                                                  Core::Types::Datatype::DtInt64::IDENTIFIER, Core::Types::Datatype::DtString::IDENTIFIER, Core::Types::Datatype::DtUInt8::IDENTIFIER,
                                                  Core::Types::Datatype::DtUInt16::IDENTIFIER, Core::Types::Datatype::DtUInt32::IDENTIFIER,
                                                  Core::Types::Datatype::DtUInt64::IDENTIFIER, Core::Types::Datatype::DtInt::IDENTIFIER,
                                                  Core::Types::Datatype::DtSizeT::IDENTIFIER, Core::Types::Datatype::DtBool::IDENTIFIER}), compareTypes(CompareTypes::EQUAL),
                              first(nullptr), second(nullptr){
        }

        void execute() override {
            //We can now be sure that only two sub-expression are contained in this expression.
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

                if(first->getIdentifier() != second->getIdentifier()) {
                    throw std::runtime_error("The datatypes of the given expression are not equal!");
                }
            }

            first->execute();
            second->execute();

            switch (this->compareTypes) {
                default:
                case CompareTypes::EQUAL:
                    this->data = Core::Types::Datatype::DtBool(first->getData() == second->getData());
                    break;
                case CompareTypes::NOT_EQUAL:
                    this->data = Core::Types::Datatype::DtBool(first->getData() != second->getData());
                    break;
                case CompareTypes::LESS_THAN:
                    this->data = Core::Types::Datatype::DtBool(first->getData() < second->getData());
                    break;
                case CompareTypes::GREATER_THAN:
                    this->data = Core::Types::Datatype::DtBool(first->getData() > second->getData());
                    break;
                case CompareTypes::LESS_THAN_OR_EQUAL:
                    this->data = Core::Types::Datatype::DtBool(first->getData() <= second->getData());
                    break;
                case CompareTypes::GREATER_THAN_OR_EQUAL:
                    this->data = Core::Types::Datatype::DtBool(first->getData() >= second->getData());
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

        [[nodiscard]] const Core::Types::Datatype::IDt& getData() const override {
            return this->data;
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }

        void setCompareType(CompareTypes type) {
            this->compareTypes = type;
        }

        CompareTypes getCompareType() {
            return this->compareTypes;
        }

    private:
        Core::Types::Datatype::DtBool data;
        CompareTypes compareTypes;
        IExpression *first, *second;
    };
}

#endif //STREAM_V1_EXPRESSION_COMPARE_COMPAREEXPRESSION_HPP
