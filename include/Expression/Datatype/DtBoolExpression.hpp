//
// Created by SlepiK on 20.03.24.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTBOOLEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTBOOLEXPRESSION_HPP

#include "Expression/IExpression.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Datatype/DtBool.hpp"

namespace Energyleaf::Stream::V1::Expression::DataType {
    class DtBoolExpression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Types::Datatype::DtBool::IDENTIFIER;

        explicit DtBoolExpression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(true) {
        }

        explicit DtBoolExpression(bool&& value) : IExpression({IDENTIFIER}), load(false), data(std::move(value)) {
        }

        ~DtBoolExpression() override = default;

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
                    this->data = this->tuple.getEntry(this->entry).get<Types::Datatype::DtBool>();
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
        Types::Datatype::DtBool data;
        bool load;
    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTBOOLEXPRESSION_HPP
