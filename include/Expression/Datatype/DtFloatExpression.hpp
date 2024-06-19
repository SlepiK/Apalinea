#ifndef APALINEA_EXPRESSION_DATATYPE_DTFLOATEXPRESSION_HPP
#define APALINEA_EXPRESSION_DATATYPE_DTFLOATEXPRESSION_HPP

#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtFloat.hpp"
#include "Expression/IExpression.hpp"

namespace Apalinea::Expression::DataType {
    class DtFloatExpression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Type::Datatype::DtFloat::IDENTIFIER;

        explicit DtFloatExpression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(true) {
        }

        explicit DtFloatExpression(float&& value) : IExpression({IDENTIFIER}), load(false), data(std::move(value)) {
        }

        ~DtFloatExpression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Core::Tuple::Tuple& tuple) override {
            if(load) {
                this->tuple = tuple;
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
                    this->data = this->tuple.getEntry(this->entry).get<Core::Type::Datatype::DtFloat>();
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
        Core::Type::Datatype::DtFloat data;
        bool load;
    };
} // Apalinea::Expression::DataType

#endif //APALINEA_EXPRESSION_DATATYPE_DTFLOATEXPRESSION_HPP
