//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTUINT8EXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTUINT8EXPRESSION_HPP

#include "Expression/Expression.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Datatype/DtUInt8.hpp"

namespace Energyleaf::Stream::V1::Expression::DataType {
    class DtUInt8Expression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Types::Datatype::DtUInt8::IDENTIFIER;

        explicit DtUInt8Expression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)) {
        }

        ~DtUInt8Expression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Tuple::Tuple& tuple) {
            this->tuple = tuple;
        }

        [[nodiscard]] const Types::Datatype::IDt& getData() const override {
            return this->data;
        }

        void execute() override {
            if(this->tuple.getItems().empty()) {
                throw std::runtime_error("Tuple is empty!");
            }

            if(this->tuple.containsItem(this->entry)) {
                this->data = this->tuple.getEntry(this->entry).get<Types::Datatype::DtUInt8>();
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
        Types::Datatype::DtUInt8 data;
    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTUINT8EXPRESSION_HPP
