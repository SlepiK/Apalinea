//
// Created by SlepiK on 19.02.24.
//

#ifndef STREAM_V1_EXPRESSION_TOEXPRESSION_TODTSTRING_HPP
#define STREAM_V1_EXPRESSION_TOEXPRESSION_TODTSTRING_HPP

#include <list>
#include <Expression/Expression.hpp>
#include <string>
#include <Types/Datatype/DtString.hpp>
#include "Types/Datatype/DtInt8.hpp"
#include "Types/Datatype/DtInt16.hpp"
#include "Types/Datatype/DtInt32.hpp"
#include "Types/Datatype/DtInt64.hpp"
#include "Types/Datatype/DtInt.hpp"
#include "Types/Datatype/DtUInt8.hpp"
#include "Types/Datatype/DtUInt16.hpp"
#include "Types/Datatype/DtUInt32.hpp"
#include "Types/Datatype/DtUInt64.hpp"
#include "Types/Datatype/DtSizeT.hpp"
#include "Types/Datatype/DtBool.hpp"
#include <Types/Datatype/DtRegistry.hpp>

namespace Energyleaf::Stream::V1::Expression {
    class ToDtStringExpression : public Expression {
    public:
        static constexpr std::string_view IDENTIFIER = Types::Datatype::DtString::IDENTIFIER;

        ToDtStringExpression() : Expression({Types::Datatype::DtInt8::IDENTIFIER, Types::Datatype::DtInt16::IDENTIFIER,
                                             Types::Datatype::DtInt32::IDENTIFIER,
                                             Types::Datatype::DtInt64::IDENTIFIER, Types::Datatype::DtInt::IDENTIFIER,
                                             Types::Datatype::DtUInt8::IDENTIFIER,
                                             Types::Datatype::DtUInt16::IDENTIFIER,
                                             Types::Datatype::DtUInt32::IDENTIFIER,
                                             Types::Datatype::DtUInt64::IDENTIFIER,
                                             Types::Datatype::DtSizeT::IDENTIFIER,
                                             Types::Datatype::DtBool::IDENTIFIER}) {
        }

        void execute() override {
            if (vSubExpressions.size() > 1) {
                throw std::runtime_error(
                        "A expression for a single sub expression, cant be executed on more then a single sub expression!");
            }
            if (vSubExpressions.empty()) {
                throw std::runtime_error("A expression can be empty!");
            }

            IExpression *exp = vSubExpressions.front();
            std::string_view expIdentifier = exp->getIdentifier();
            if (!this->isDatatypeAllowed(expIdentifier)) {
                throw std::runtime_error("The datatype returned from the given expression is not allowed!");
            }

            exp->execute();
            const Types::Datatype::IDt &expData = exp->getData();
            Types::Datatype::DtRegistry::DtRegistryIndex tmpDataIndex = Types::Datatype::DtRegistry::get(
                    expData.getIdentifier());

            if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtInt8::IDENTIFIER) &&
                tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtInt8::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtInt8 &>(expData)).toInt8()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtInt16::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtInt16::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtInt16 &>(expData)).toInt16()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtInt32::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtInt32::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtInt32 &>(expData)).toInt32()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtInt64::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtInt64::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtInt64 &>(expData)).toInt64()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtUInt8::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtUInt8::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtUInt8 &>(expData)).toUInt8()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtUInt16::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtUInt16::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtUInt16 &>(expData)).toUInt16()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtUInt32::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtUInt32::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtUInt32 &>(expData)).toUInt32()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtUInt64::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtUInt64::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtUInt64 &>(expData)).toUInt64()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtInt::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtInt::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtInt &>(expData)).toInt()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtSizeT::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtSizeT::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        std::to_string((static_cast<const Types::Datatype::DtSizeT &>(expData)).toSizeT()));
            } else if (Types::Datatype::DtRegistry::isRegistered(Types::Datatype::DtBool::IDENTIFIER) &&
                       tmpDataIndex == Types::Datatype::DtRegistry::get(Types::Datatype::DtBool::IDENTIFIER)) {
                this->data = Types::Datatype::DtString(
                        (static_cast<const Types::Datatype::DtBool &>(expData)).toBool() ? "true" : "false");
            } else {
                throw std::runtime_error("Cant convert given type to string!");
            }
        }

        [[nodiscard]] const Types::Datatype::IDt &getData() const override {
            return this->data;
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }

    private:
        Types::Datatype::DtString data;
    };
}

#endif //STREAM_V1_EXPRESSION_TOEXPRESSION_TODTSTRING_HPP
