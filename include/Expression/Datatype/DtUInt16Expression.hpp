//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTUINT16EXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTUINT16EXPRESSION_HPP

#include "Expression/Expression.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Datatype/DtUInt16.hpp"

namespace Energyleaf::Stream::V1::Expression::DataType {
    class DtUInt16Expression : public Expression {
    public:
        explicit DtUInt16Expression(std::string&& entry) : entry(std::move(entry)) {
            this->setMax(1);
        }

        ~DtUInt16Expression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Tuple::Tuple& tuple) {
            this->tuple = tuple;
        }

        const Types::Datatype::DtUInt16& getData() {
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
    private:
        Tuple::Tuple tuple;
        std::string entry;
        Types::Datatype::DtUInt16 data;
    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTUINT16EXPRESSION_HPP
