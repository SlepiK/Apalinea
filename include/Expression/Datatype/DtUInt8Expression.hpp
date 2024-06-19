#ifndef APALINEA_EXPRESSION_DATATYPE_DTUINT8EXPRESSION_HPP
#define APALINEA_EXPRESSION_DATATYPE_DTUINT8EXPRESSION_HPP

#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtUInt8.hpp"
#include "Expression/IExpression.hpp"

namespace Apalinea::Expression::DataType {
    class [[maybe_unused]] DtUInt8Expression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Type::Datatype::DtUInt8::IDENTIFIER;

        [[maybe_unused]] explicit DtUInt8Expression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(true) {
        }

        [[maybe_unused]] explicit DtUInt8Expression(uint8_t&& value) : IExpression({IDENTIFIER}), load(false), data(value) {
        }

        ~DtUInt8Expression() override = default;

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
            if(this->tuple.getItems().empty()) {
                throw std::runtime_error("Tuple is empty!");
            }

            if(this->tuple.containsItem(this->entry)) {
                this->data = this->tuple.getEntry(this->entry).get<Core::Type::Datatype::DtUInt8>();
            } else {
                throw std::runtime_error("Entry was not found in the given tuple!");
            }
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }

    private:
        Core::Tuple::Tuple tuple;
        std::string entry;
        Core::Type::Datatype::DtUInt8 data;
        bool load;
    };
} // Apalinea::Expression::DataType

#endif //APALINEA_EXPRESSION_DATATYPE_DTUINT8EXPRESSION_HPP
