#ifndef APALINEA_EXPRESSION_TOEXPRESSION_TODTDOUBLEEXPRESSION_HPP
#define APALINEA_EXPRESSION_TOEXPRESSION_TODTDOUBLEEXPRESSION_HPP

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
        static constexpr std::string_view IDENTIFIER = Core::Type::Datatype::DtDouble::IDENTIFIER;

        ToDtDoubleExpression() : AbstractExpression({Core::Type::Datatype::DtInt8::IDENTIFIER, Core::Type::Datatype::DtInt16::IDENTIFIER, Core::Type::Datatype::DtInt32::IDENTIFIER,
                                                     Core::Type::Datatype::DtInt64::IDENTIFIER, Core::Type::Datatype::DtUInt8::IDENTIFIER,
                                                     Core::Type::Datatype::DtUInt16::IDENTIFIER, Core::Type::Datatype::DtUInt32::IDENTIFIER,
                                                     Core::Type::Datatype::DtUInt64::IDENTIFIER, Core::Type::Datatype::DtDouble::IDENTIFIER,
                                                     Core::Type::Datatype::DtFloat::IDENTIFIER, Core::Type::Datatype::DtBool::IDENTIFIER, Core::Type::Datatype::DtInt::IDENTIFIER,
                                                     Core::Type::Datatype::DtSizeT::IDENTIFIER}) {
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

            const Core::Type::Datatype::IDt &expData = exp->getData();
            Core::Type::Datatype::DtRegistry::DtRegistryIndex tmpDataIndex = Core::Type::Datatype::DtRegistry::get(
                    expData.getIdentifier());
            if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtInt8::IDENTIFIER) &&
                tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtInt8::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble((static_cast<const Core::Type::Datatype::DtInt8 &>(expData)).toInt8());
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtInt16::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtInt16::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        (static_cast<const Core::Type::Datatype::DtInt16 &>(expData)).toInt16());
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtInt32::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtInt32::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        (static_cast<const Core::Type::Datatype::DtInt32 &>(expData)).toInt32());
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtInt64::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtInt64::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Type::Datatype::DtInt64 &>(expData)).toInt64()));
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtUInt8::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtUInt8::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        (static_cast<const Core::Type::Datatype::DtUInt8 &>(expData)).toUInt8());
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtUInt16::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtUInt16::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        (static_cast<const Core::Type::Datatype::DtUInt16 &>(expData)).toUInt16());
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtUInt32::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtUInt32::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        (static_cast<const Core::Type::Datatype::DtUInt32 &>(expData)).toUInt32());
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtUInt64::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtUInt64::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Type::Datatype::DtUInt64 &>(expData)).toUInt64()));
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtFloat::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtFloat::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Type::Datatype::DtFloat &>(expData)).toFloat()));
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtDouble::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtDouble::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        (static_cast<const Core::Type::Datatype::DtDouble &>(expData)).toDouble());
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtSizeT::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtSizeT::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Type::Datatype::DtSizeT &>(expData)).toSizeT()));
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtInt::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtInt::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble(
                        static_cast<double>((static_cast<const Core::Type::Datatype::DtInt &>(expData)).toInt()));
            } else if (Core::Type::Datatype::DtRegistry::isRegistered(Core::Type::Datatype::DtBool::IDENTIFIER) &&
                       tmpDataIndex == Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtBool::IDENTIFIER)) {
                this->data = Core::Type::Datatype::DtDouble((static_cast<const Core::Type::Datatype::DtBool &>(expData)).toBool());
            } else {
                throw std::runtime_error("Cant convert given type to string!");
            }
        }

        [[nodiscard]] const Core::Type::Datatype::IDt& getData() const override {
            return this->data;
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }

    private:
        Core::Type::Datatype::DtDouble data;
    };
} // Apalinea::Expression

#endif //APALINEA_EXPRESSION_TOEXPRESSION_TODTDOUBLEEXPRESSION_HPP
