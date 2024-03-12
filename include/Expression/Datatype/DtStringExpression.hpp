//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTSTRINGEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTSTRINGEXPRESSION_HPP

#include "Expression/Expression.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Datatype/DtString.hpp"

namespace Energyleaf::Stream::V1::Expression::DataType {
    class DtStringExpression : public Expression {
    public:
        explicit DtStringExpression(std::string&& entry) : entry(std::move(entry)) {
            this->setMax(1);
        }

        ~DtStringExpression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Tuple::Tuple& tuple) {
            this->tuple = tuple;
        }

        const Types::Datatype::DtString& getData() {
            return this->data;
        }

        void execute() override {
            if(this->tuple.getItems().empty()) {
                throw std::runtime_error("Tuple is empty!");
            }

            if(this->tuple.containsItem(this->entry)) {
                this->data = this->tuple.getEntry(this->entry).get<Types::Datatype::DtString>();
            } else {
                throw std::runtime_error("Entry was not found in the given tuple!");
            }
        }
    private:
        Tuple::Tuple tuple;
        std::string entry;
        Types::Datatype::DtString data;

    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTSTRINGEXPRESSION_HPP
