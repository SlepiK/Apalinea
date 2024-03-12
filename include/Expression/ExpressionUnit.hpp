//
// Created by SlepiK on 19.02.24.
//

#ifndef STREAM_V1_EXPRESSION_EXPRESSIONUNIT_HPP
#define STREAM_V1_EXPRESSION_EXPRESSIONUNIT_HPP

#include "IExpression.hpp"
#include <Tuple/Tuple.hpp>
#include <Tuple/Item/DepItem.hpp>
#include <string>

namespace Energyleaf::Stream::V1::Expression {
    class ExpressionUnit : public IExpression {
    public:
        explicit ExpressionUnit(std::string&& unitName)
        : vUnitName(std::move(unitName)) {
        }

        virtual ~ExpressionUnit() = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

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

        Tuple::Entry& getEntry() {
            return this->vUnitEntry;
        }

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
