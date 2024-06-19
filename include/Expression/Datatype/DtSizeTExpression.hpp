#ifndef APALINEA_EXPRESSION_DATATYPE_DTSIZETEXPRESSION_HPP
#define APALINEA_EXPRESSION_DATATYPE_DTSIZETEXPRESSION_HPP

#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtSizeT.hpp"
#include "Expression/IExpression.hpp"

namespace Apalinea::Expression::DataType {
    class DtSizeTExpression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Type::Datatype::DtSizeT::IDENTIFIER;

        explicit DtSizeTExpression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(true) {
        }

        explicit DtSizeTExpression(std::size_t&& value) : IExpression({IDENTIFIER}), load(false), data(std::move(value)) {
        }

        ~DtSizeTExpression() override = default;

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
                    this->data = this->tuple.getEntry(this->entry).get<Core::Type::Datatype::DtSizeT>();
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
        Core::Type::Datatype::DtSizeT data;
        bool load;
    };
} // Apalinea::Expression::DataType

#endif //APALINEA_EXPRESSION_DATATYPE_DTSIZETEXPRESSION_HPP
