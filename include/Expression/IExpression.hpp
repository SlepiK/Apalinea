//
// Created by SlepiK on 19.02.24.
//

#ifndef STREAM_V1_EXPRESSION_IEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_IEXPRESSION_HPP

#include <stdexcept>

namespace Energyleaf::Stream::V1::Expression {
    class IExpression {
    public:
        virtual ~IExpression() = default;

        void setHeadExpression(IExpression *expression) {
            this->vHeadExpression = expression;
        }

        [[nodiscard]] IExpression *getHeadExpression() const {
            return this->vHeadExpression;
        }

        virtual void add(IExpression *component) {
            throw std::runtime_error("Operation is not direct supported!");
        }

        virtual void remove(IExpression *component) {
            throw std::runtime_error("Operation is not direct supported!");
        }

        [[nodiscard]] virtual bool isComposite() const = 0;

        virtual void execute() = 0;
    protected:
        IExpression *vHeadExpression;
    };
}

#endif //STREAM_V1_EXPRESSION_IEXPRESSION_HPP
