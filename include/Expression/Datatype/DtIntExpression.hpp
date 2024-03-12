//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTINTEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTINTEXPRESSION_HPP

#include "Expression/Expression.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Datatype/DtInt.hpp"

namespace Energyleaf::Stream::V1::Expression::DataType {
    class DtIntExpression : public Expression {
    public:
        explicit DtIntExpression(std::string&& entry) : entry(std::move(entry)) {
            this->setMax(1);
        }

        ~DtIntExpression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Tuple::Tuple& tuple) {
            this->tuple = tuple;
        }

        const Types::Datatype::DtInt& getData() {
            return this->data;
        }

        void execute() override {
            if(this->tuple.getItems().empty()) {
                throw std::runtime_error("Tuple is empty!");
            }

            if(this->tuple.containsItem(this->entry)) {
                this->data = this->tuple.getEntry(this->entry).get<Types::Datatype::DtInt>();
            } else {
                throw std::runtime_error("Entry was not found in the given tuple!");
            }
        }
    private:
        Tuple::Tuple tuple;
        std::string entry;
        Types::Datatype::DtInt data;

    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTINTEXPRESSION_HPP
