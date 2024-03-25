//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXPRESSION_TOEXPRESSION_TODTINT_HPP
#define STREAM_V1_EXPRESSION_TOEXPRESSION_TODTINT_HPP

#include "Expression/Expression.hpp"
#include "Types/Datatype/DtInt.hpp"
#include <Types/Datatype/DtString.hpp>
#include "Types/Datatype/DtInt8.hpp"
#include "Types/Datatype/DtInt16.hpp"
#include "Types/Datatype/DtInt32.hpp"
#include "Types/Datatype/DtInt64.hpp"
#include "Types/Datatype/DtUInt8.hpp"
#include "Types/Datatype/DtUInt16.hpp"
#include "Types/Datatype/DtBool.hpp"
#include <Types/Datatype/DtRegistry.hpp>

namespace Energyleaf::Stream::V1::Expression {
    class ToDtIntExpression : public Expression {
    public:
        static constexpr std::string_view IDENTIFIER = Types::Datatype::DtInt::IDENTIFIER;

        ToDtIntExpression() : Expression({Types::Datatype::DtInt8::IDENTIFIER,Types::Datatype::DtInt16::IDENTIFIER,Types::Datatype::DtInt32::IDENTIFIER,
                                          Types::Datatype::DtString::IDENTIFIER,Types::Datatype::DtUInt8::IDENTIFIER,
                                             Types::Datatype::DtUInt16::IDENTIFIER, Types::Datatype::DtBool::IDENTIFIER}) {
        }

        void execute() override {
            if(vSubExpressions.size() > 1) {
                throw std::runtime_error("A expression for a single sub expression, cant be executed on more then a single sub expression!");
            }
            if(vSubExpressions.empty()) {
                throw std::runtime_error("A expression can be empty!");
            }

            IExpression* exp = vSubExpressions.front();
            std::string_view expIdentifier = exp->getIdentifier();
            if(!this->isDatatypeAllowed(expIdentifier)) {
                throw std::runtime_error("The datatype returned from the given expression is not allowed!");
            }

            exp->execute();
            const Types::Datatype::IDt& expData = exp->getData();
            Types::Datatype::DtRegistry::DtRegistryIndex tmpDataIndex = Types::Datatype::DtRegistry::get(expData.getIdentifier());
            if(!exp->isComposite()) {//ToDo: Rewrite that code.
                if(Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtInt8::IDENTIFIER) && tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtInt8::IDENTIFIER)) {
                    this->data = Types::Datatype::DtInt((static_cast<const Types::Datatype::DtInt8&>(expData)).toInt8());
                } else if(Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtInt16::IDENTIFIER) && tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtInt16::IDENTIFIER)) {
                    this->data = Types::Datatype::DtInt((static_cast<const Types::Datatype::DtInt16&>(expData)).toInt16());
                } else if(Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtInt32::IDENTIFIER) && tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtInt32::IDENTIFIER)) {
                    this->data = Types::Datatype::DtInt((static_cast<const Types::Datatype::DtInt32&>(expData)).toInt32());
                } else if(Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtUInt8::IDENTIFIER) && tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtUInt8::IDENTIFIER)) {
                    this->data = Types::Datatype::DtInt((static_cast<const Types::Datatype::DtUInt8&>(expData)).toUInt8());
                } else if(Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtUInt16::IDENTIFIER) && tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtUInt16::IDENTIFIER)) {
                    this->data = Types::Datatype::DtInt((static_cast<const Types::Datatype::DtUInt16&>(expData)).toUInt16());
                } else if(Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtString::IDENTIFIER) && tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtString::IDENTIFIER)) {
                    this->data = Types::Datatype::DtInt(
                            std::stoi((static_cast<const Types::Datatype::DtString&>(expData)).toString()));
                } else if(Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtBool::IDENTIFIER) && tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtBool::IDENTIFIER)) {
                    this->data = Types::Datatype::DtInt((static_cast<const Types::Datatype::DtBool&>(expData)).toBool());
                } else {
                    throw std::runtime_error("Cant convert given type to string!");
                }
            } else {
                throw std::runtime_error("This expression cant be used as first expression!");
            }
        }

        [[nodiscard]] const Types::Datatype::IDt& getData() const override {
            return this->data;
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }
    private:
        Types::Datatype::DtInt data;
    };
}

#endif //STREAM_V1_EXPRESSION_TOEXPRESSION_TODTINT_HPP
