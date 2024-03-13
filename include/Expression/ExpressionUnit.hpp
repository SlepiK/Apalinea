//
// Created by SlepiK on 19.02.24.
//

#ifndef STREAM_V1_EXPRESSION_EXPRESSIONUNIT_HPP
#define STREAM_V1_EXPRESSION_EXPRESSIONUNIT_HPP

#include "IExpression.hpp"
#include <Tuple/Tuple.hpp>
#include <string>

namespace Energyleaf::Stream::V1::Expression {
    class ExpressionUnit : public IExpression {
    public:

        [[deprecated]]
        explicit ExpressionUnit(std::string &&unitName)
        : IExpression({""}), vUnitName(std::move(unitName)) {
        }

        [[deprecated]]
        virtual ~ExpressionUnit() = default;

        [[deprecated]]
        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        [[deprecated]]
        void execute() override {
            if(this->vTuple.getItems().empty()) {
                throw std::runtime_error("No tuple was loaded!");
            }
            if(this->vTuple.containsItem(this->vUnitName)) {
                this->vUnitEntry = this->vTuple.getEntry(this->vUnitName);
            } else {
                throw std::runtime_error("Unit/Entry/DepItem could not found in the tuple!");
            }
        }

        [[deprecated]]
        Tuple::Entry& getEntry() {
            return this->vUnitEntry;
        }

        [[deprecated]]
        void setTuple(Tuple::Tuple& tuple) {
            this->vTuple = tuple;
        }
    private:
        Tuple::Tuple vTuple;
        std::string vUnitName;
        Tuple::Entry vUnitEntry;
    };
    using Unit = ExpressionUnit;
}

#endif //STREAM_V1_EXPRESSION_EXPRESSIONUNIT_HPP
