//
// Created by SlepiK on 25.03.24.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTDOUBLEEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTDOUBLEEXPRESSION_HPP

#include "Expression/IExpression.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Datatype/DtDouble.hpp"

namespace Energyleaf::Stream::V1::Expression::DataType {
    class DtDoubleExpression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Types::Datatype::DtFloat::IDENTIFIER;

        explicit DtDoubleExpression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(true) {
        }

        explicit DtDoubleExpression(double&& value) : IExpression({IDENTIFIER}), load(false), data(std::move(value)) {
        }

        ~DtDoubleExpression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Tuple::Tuple& tuple) {
            if(load) {
                this->tuple = tuple;
            }
        }

        [[nodiscard]] const Types::Datatype::IDt& getData() const override {
            return this->data;
        }

        void execute() override {
            if(load) {
                if (this->tuple.getItems().empty()) {
                    throw std::runtime_error("Tuple is empty!");
                }

                if (this->tuple.containsItem(this->entry)) {
                    this->data = this->tuple.getEntry(this->entry).get<Types::Datatype::DtDouble>();
                } else {
                    throw std::runtime_error("Entry was not found in the given tuple!");
                }
            }
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }
    private:
        Tuple::Tuple tuple;
        std::string entry;
        Types::Datatype::DtDouble data;
        bool load;
    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTDOUBLEEXPRESSION_HPP
