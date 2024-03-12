//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTINT64EXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTINT64EXPRESSION_HPP

#include "Expression/Expression.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Datatype/DtInt64.hpp"

namespace Energyleaf::Stream::V1::Expression::DataType {
    class DtInt64Expression : public Expression {
    public:
        explicit DtInt64Expression(std::string&& entry) : entry(std::move(entry)) {
            this->setMax(1);
        }

        ~DtInt64Expression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Tuple::Tuple& tuple) {
            this->tuple = tuple;
        }

        const Types::Datatype::DtInt64& getData() {
            return this->data;
        }

        void execute() override {
            if(this->tuple.getItems().empty()) {
                throw std::runtime_error("Tuple is empty!");
            }

            if(this->tuple.containsItem(this->entry)) {
                this->data = this->tuple.getEntry(this->entry).get<Types::Datatype::DtInt64>();
            } else {
                throw std::runtime_error("Entry was not found in the given tuple!");
            }
        }
    private:
        Tuple::Tuple tuple;
        std::string entry;
        Types::Datatype::DtInt64 data;

    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTINT64EXPRESSION_HPP
