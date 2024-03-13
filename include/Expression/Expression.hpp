//
// Created by SlepiK on 19.02.24.
//

#ifndef STREAM_V1_EXPRESSION_EXPRESSION_HPP
#define STREAM_V1_EXPRESSION_EXPRESSION_HPP

#include <list>
#include <utility>
#include "IExpression.hpp"

namespace Energyleaf::Stream::V1::Expression {
    class Expression : public IExpression {
    public:
        explicit Expression(std::vector<std::string_view> datatypes) : IExpression(std::move(datatypes)){
        }

        ~Expression() override = default;

        void add(IExpression *expression) override {
            if(this->vSubExpressions.size() <= this->vMax) {
                this->vSubExpressions.push_back(expression);
                expression->setHeadExpression(this);
            } else {
                throw std::runtime_error("Limit of expression already reached!");
            }
        }

        void remove(IExpression *expression) override {
            if(this->vSubExpressions.empty()) {
                throw std::runtime_error("Cant remove expression if no subexpression is known!");
            } else {
                vSubExpressions.remove(expression);
                expression->setHeadExpression(nullptr);
            }
        }

        [[nodiscard]] bool isComposite() const override {
            return true;
        }
    private:
        unsigned int vMax = 1;
    protected:
        std::list<IExpression*> vSubExpressions;

        void setMax(unsigned int max) {
            if(max > 0) this->vMax = max;
            else throw std::runtime_error("Cant set max below 1!");
        }
    };
}

#endif //STREAM_V1_EXPRESSION_EXPRESSION_HPP
