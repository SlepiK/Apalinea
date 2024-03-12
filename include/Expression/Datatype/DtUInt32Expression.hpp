//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTUINT32EXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTUINT32EXPRESSION_HPP

#include "Expression/Expression.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Datatype/DtUInt32.hpp"

namespace Energyleaf::Stream::V1::Expression::DataType {
    class DtUInt32Expression : public Expression {
    public:
        explicit DtUInt32Expression(std::string&& entry) : entry(std::move(entry)) {
            this->setMax(1);
        }

        ~DtUInt32Expression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Tuple::Tuple& tuple) {
            this->tuple = tuple;
        }

        const Types::Datatype::DtUInt32& getData() {
            return this->data;
        }

        void execute() override {
            if(this->tuple.getItems().empty()) {
                throw std::runtime_error("Tuple is empty!");
            }

            if(this->tuple.containsItem(this->entry)) {
                this->data = this->tuple.getEntry(this->entry).get<Types::Datatype::DtUInt32>();
            } else {
                throw std::runtime_error("Entry was not found in the given tuple!");
            }
        }
    private:
        Tuple::Tuple tuple;
        std::string entry;
        Types::Datatype::DtUInt32 data;
    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTUINT32EXPRESSION_HPP
