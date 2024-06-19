//
// Created by SlepiK on 26.03.24.
//

#ifndef STREAM_V1_EXPRESSION_TODTDOUBLEEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_TODTDOUBLEEXPRESSION_HPP

#include "Core/Type/Datatype/DtRegistry.hpp"
#include "Core/Type/Datatype/DtInt.hpp"
#include "Core/Type/Datatype/DtInt8.hpp"
#include "Core/Type/Datatype/DtInt16.hpp"
#include "Core/Type/Datatype/DtInt32.hpp"
#include "Core/Type/Datatype/DtInt64.hpp"
#include "Core/Type/Datatype/DtUInt8.hpp"
#include "Core/Type/Datatype/DtUInt16.hpp"
#include "Core/Type/Datatype/DtBool.hpp"
#include "Core/Type/Datatype/DtFloat.hpp"
#include "Core/Type/Datatype/DtDouble.hpp"
#include "Core/Type/Datatype/DtSizeT.hpp"
#include "Expression/AbstractExpression.hpp"

namespace Apalinea::Expression {
    class ToDtDoubleExpression : public AbstractExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Types::Datatype::DtDouble::IDENTIFIER;

        ToDtDoubleExpression() : AbstractExpression({Core::Types::Datatype::DtInt8::IDENTIFIER, Core::Types::Datatype::DtInt16::IDENTIFIER, Core::Types::Datatype::DtInt32::IDENTIFIER,
                                                     Core::Types::Datatype::DtInt64::IDENTIFIER, Core::Types::Datatype::DtUInt8::IDENTIFIER,
                                                     Core::Types::Datatype::DtUInt16::IDENTIFIER, Core::Types::Datatype::DtUInt32::IDENTIFIER,
                                                     Core::Types::Datatype::DtUInt64::IDENTIFIER, Core::Types::Datatype::DtDouble::IDENTIFIER,
                                                     Core::Types::Datatype::DtFloat::IDENTIFIER, Core::Types::Datatype::DtBool::IDENTIFIER, Core::Types::Datatype::DtInt::IDENTIFIER,
                                                     Core::Types::Datatype::DtSizeT::IDENTIFIER}) {
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

            const Core::Types::Datatype::IDt &expData = exp->getData();
            Core::Types::Datatype::DtRegistry::DtRegistryIndex tmpDataIndex = Core::Types::Datatype::DtRegistry::get(
                    expData.getIdentifier());
            if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtInt8::IDENTIFIER) &&
                tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtInt8::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble((static_cast<const Core::Types::Datatype::DtInt8 &>(expData)).toInt8());
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtInt16::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtInt16::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        (static_cast<const Core::Types::Datatype::DtInt16 &>(expData)).toInt16());
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtInt32::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtInt32::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        (static_cast<const Core::Types::Datatype::DtInt32 &>(expData)).toInt32());
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtInt64::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtInt64::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Types::Datatype::DtInt64 &>(expData)).toInt64()));
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtUInt8::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtUInt8::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        (static_cast<const Core::Types::Datatype::DtUInt8 &>(expData)).toUInt8());
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtUInt16::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtUInt16::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        (static_cast<const Core::Types::Datatype::DtUInt16 &>(expData)).toUInt16());
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtUInt32::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtUInt32::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        (static_cast<const Core::Types::Datatype::DtUInt32 &>(expData)).toUInt32());
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtUInt64::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtUInt64::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Types::Datatype::DtUInt64 &>(expData)).toUInt64()));
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtFloat::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtFloat::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Types::Datatype::DtFloat &>(expData)).toFloat()));
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtDouble::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtDouble::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        (static_cast<const Core::Types::Datatype::DtDouble &>(expData)).toDouble());
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtSizeT::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtSizeT::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Types::Datatype::DtSizeT &>(expData)).toSizeT()));
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtInt::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtInt::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Types::Datatype::DtInt &>(expData)).toInt()));
            } else if (Core::Types::Datatype::DtRegistry::isRegistered(Core::Types::Datatype::DtBool::IDENTIFIER) &&
                       tmpDataIndex == Core::Types::Datatype::DtRegistry::get(Core::Types::Datatype::DtBool::IDENTIFIER)) {
                this->data = Core::Types::Datatype::DtDouble((static_cast<const Core::Types::Datatype::DtBool &>(expData)).toBool());
            } else {
                throw std::runtime_error("Cant convert given type to string!");
            }
        }

        [[nodiscard]] const Core::Types::Datatype::IDt& getData() const override {
            return this->data;
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }
    private:
        Core::Types::Datatype::DtDouble data;
    };
}

#endif //STREAM_V1_EXPRESSION_TODTDOUBLEEXPRESSION_HPP
