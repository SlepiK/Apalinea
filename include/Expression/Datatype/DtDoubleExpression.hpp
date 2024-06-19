#ifndef APALINEA_EXPRESSION_DATATYPE_DTDOUBLEEXPRESSION_HPP
#define APALINEA_EXPRESSION_DATATYPE_DTDOUBLEEXPRESSION_HPP

#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtDouble.hpp"
#include "Expression/IExpression.hpp"

namespace Apalinea::Expression::DataType {
    class [[maybe_unused]] DtDoubleExpression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Type::Datatype::DtFloat::IDENTIFIER;

        [[maybe_unused]] explicit DtDoubleExpression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(true) {
        }

        [[maybe_unused]] explicit DtDoubleExpression(double&& value) : IExpression({IDENTIFIER}), load(false), data(value) {
        }

        ~DtDoubleExpression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Core::Tuple::Tuple& inputTupel) override {
            if(load) {
                this->tuple = inputTupel;
            }
        }

        [[nodiscard]] const Core::Type::Datatype::IDt& getData() const override {
            return this->data;
        }

        void execute() override {
            if(load) {
                if (this->tuple.getItems().empty()) {
                    throw std::runtime_error("Tuple is empty!");
                }

                if (this->tuple.containsItem(this->entry)) {
                    this->data = this->tuple.getEntry(this->entry).get<Core::Type::Datatype::DtDouble>();
                } else {
                    throw std::runtime_error("Entry was not found in the given tuple!");
                }
            }
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }

    private:
        Core::Tuple::Tuple tuple;
        std::string entry;
        Core::Type::Datatype::DtDouble data;
        bool load;
    };
} // Apalinea::Expression::DataType

#endif //APALINEA_EXPRESSION_DATATYPE_DTDOUBLEEXPRESSION_HPP
