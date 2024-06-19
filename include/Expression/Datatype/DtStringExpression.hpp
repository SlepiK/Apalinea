#ifndef APALINEA_EXPRESSION_DATATYPE_DTSTRINGEXPRESSION_HPP
#define APALINEA_EXPRESSION_DATATYPE_DTSTRINGEXPRESSION_HPP

#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtString.hpp"
#include "Expression/IExpression.hpp"

namespace Apalinea::Expression::DataType {
    class [[maybe_unused]] DtStringExpression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Type::Datatype::DtString::IDENTIFIER;

        [[maybe_unused]] explicit DtStringExpression(std::string&& entry, bool load = true) :
        IExpression({IDENTIFIER}), load(load) {
            if(load) {
                this->entry = std::move(entry);
            } else {
                this->data = Core::Type::Datatype::DtString(std::move(entry));
            }
        }

        ~DtStringExpression() override = default;

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
                    this->data = this->tuple.getEntry(this->entry).get<Core::Type::Datatype::DtString>();
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
        Core::Type::Datatype::DtString data;
        bool load;
    };
} // Apalinea::Expression::DataType

#endif //APALINEA_EXPRESSION_DATATYPE_DTSTRINGEXPRESSION_HPP
