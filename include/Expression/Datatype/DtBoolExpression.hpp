//
// Created by SlepiK on 20.03.24.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTBOOLEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTBOOLEXPRESSION_HPP

#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtBool.hpp"
#include "Expression/IExpression.hpp"

namespace Apalinea::Expression::DataType {
    class DtBoolExpression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Types::Datatype::DtBool::IDENTIFIER;

        explicit DtBoolExpression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(true) {
        }

        explicit DtBoolExpression(bool&& value) : IExpression({IDENTIFIER}), load(false), data(std::move(value)) {
        }

        ~DtBoolExpression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Core::Tuple::Tuple& tuple) override {
            if(load) {
                this->tuple = tuple;
            }
        }

        [[nodiscard]] const Core::Types::Datatype::IDt& getData() const override {
            return this->data;
        }

        void execute() override {
            if(load) {
                if (this->tuple.getItems().empty()) {
                    throw std::runtime_error("Tuple is empty!");
                }

                if (this->tuple.containsItem(this->entry)) {
                    this->data = this->tuple.getEntry(this->entry).get<Core::Types::Datatype::DtBool>();
                } else {
                    throw std::runtime_error("Entry was not found in the given tuple!");
                }
            }
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }
    private:
        Core::Tuple::Tuple tuple;
        std::string entry;
        Core::Types::Datatype::DtBool data;
        bool load;
    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTBOOLEXPRESSION_HPP
