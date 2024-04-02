//
// Created by SlepiK on 19.03.24.
//

#ifndef STREAM_V1_EXPRESSION_COMPARE_COMPAREEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_COMPARE_COMPAREEXPRESSION_HPP

#include "Expression/Expression.hpp"
#include "Types/Datatype/DtBool.hpp"
#include "Types/Datatype/DtString.hpp"
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

namespace Energyleaf::Stream::V1::Expression::Compare {
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

    class CompareExpression : public Expression {
    public:
        static constexpr std::string_view IDENTIFIER = Types::Datatype::DtBool::IDENTIFIER;

        CompareExpression() : Expression({Types::Datatype::DtInt8::IDENTIFIER,Types::Datatype::DtInt16::IDENTIFIER,Types::Datatype::DtInt32::IDENTIFIER,
                                          Types::Datatype::DtInt64::IDENTIFIER, Types::Datatype::DtString::IDENTIFIER,Types::Datatype::DtUInt8::IDENTIFIER,
                                          Types::Datatype::DtUInt16::IDENTIFIER,Types::Datatype::DtUInt32::IDENTIFIER,
                                          Types::Datatype::DtUInt64::IDENTIFIER, Types::Datatype::DtInt::IDENTIFIER,
                                          Types::Datatype::DtSizeT::IDENTIFIER, Types::Datatype::DtBool::IDENTIFIER}), compareTypes(CompareTypes::EQUAL),
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
                    this->data = Types::Datatype::DtBool(first->getData() == second->getData());
                    break;
                case CompareTypes::NOT_EQUAL:
                    this->data = Types::Datatype::DtBool(first->getData() != second->getData());
                    break;
                case CompareTypes::LESS_THAN:
                    this->data = Types::Datatype::DtBool(first->getData() < second->getData());
                    break;
                case CompareTypes::GREATER_THAN:
                    this->data = Types::Datatype::DtBool(first->getData() > second->getData());
                    break;
                case CompareTypes::LESS_THAN_OR_EQUAL:
                    this->data = Types::Datatype::DtBool(first->getData() <= second->getData());
                    break;
                case CompareTypes::GREATER_THAN_OR_EQUAL:
                    this->data = Types::Datatype::DtBool(first->getData() >= second->getData());
                    break;
            }
        }

        void setTuple(Tuple::Tuple& tuple) override {
            if(first == nullptr && second == nullptr) {
                for (IExpression *exp: vSubExpressions) {
                    exp->setTuple(tuple);
                }
            } else {
                first->setTuple(tuple);
                second->setTuple(tuple);
            }
        }

        [[nodiscard]] const Types::Datatype::IDt& getData() const override {
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
        Types::Datatype::DtBool data;
        CompareTypes compareTypes;
        IExpression *first, *second;
    };
}

#endif //STREAM_V1_EXPRESSION_COMPARE_COMPAREEXPRESSION_HPP
