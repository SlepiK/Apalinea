//
// Created by SlepiK on 19.02.24.
//

#ifndef STREAM_V1_EXPRESSION_TOEXPRESSION_TOSTRING_HPP
#define STREAM_V1_EXPRESSION_TOEXPRESSION_TOSTRING_HPP

#include <list>
#include <Expression/Expression.hpp>
#include <Expression/ExpressionUnit.hpp>
#include <string>
#include <Types/Base/StringItem.hpp>

namespace Energyleaf::Stream::V1::Expression {
    class ToStringExpression : public Expression {
    public:
        ToStringExpression() {
            this->setMax(1);
        }

        void execute() override {
            for(IExpression* expression : vSubExpressions) {
                if(!expression->isComposite()) {
                    expression->execute();
                    this->vValue = (static_cast<ExpressionUnit*>(expression))->getEntry().get<Types::Base::StringItem>().toString();
                } else {
                    throw std::runtime_error("Something went wrong!");
                }
                expression->execute();
            }
        }

        std::string& getString() {
            return this->vValue;
        }
    private:
        std::string vValue;
    };
}

#endif //STREAM_V1_EXPRESSION_TOEXPRESSION_TOSTRING_HPP
