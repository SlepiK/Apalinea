//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTUINT16EXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTUINT16EXPRESSION_HPP

#include "Expression/Expression.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Datatype/DtUInt16.hpp"

namespace Energyleaf::Stream::V1::Expression::DataType {
    class DtUInt16Expression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Types::Datatype::DtUInt16::IDENTIFIER;

        explicit DtUInt16Expression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(true) {
        }

        explicit DtUInt16Expression(uint16_t&& value) : IExpression({IDENTIFIER}), load(false), data(value) {
        }

        ~DtUInt16Expression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Tuple::Tuple& tuple) override {
            if(load) {
                this->tuple = tuple;
            }
        }

        [[nodiscard]] const Types::Datatype::IDt& getData() const override {
            return this->data;
        }

        void execute() override {
            if(this->tuple.getItems().empty()) {
                throw std::runtime_error("Tuple is empty!");
            }

            if(this->tuple.containsItem(this->entry)) {
                this->data = this->tuple.getEntry(this->entry).get<Types::Datatype::DtUInt16>();
            } else {
                throw std::runtime_error("Entry was not found in the given tuple!");
            }
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }
    private:
        Tuple::Tuple tuple;
        std::string entry;
        Types::Datatype::DtUInt16 data;
        bool load;
    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTUINT16EXPRESSION_HPP
