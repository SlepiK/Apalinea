//
// Created by SlepiK on 19.02.24.
//

#ifndef STREAM_V1_EXPRESSION_TOEXPRESSION_TOSTRING_HPP
#define STREAM_V1_EXPRESSION_TOEXPRESSION_TOSTRING_HPP

#include <list>
#include <Expression/Expression.hpp>
#include <Expression/ExpressionUnit.hpp>
#include <string>
#include <Types/Datatype/DtString.hpp>

namespace Energyleaf::Stream::V1::Expression {
    class ToDtStringExpression : public Expression {
    public:
        ToDtStringExpression() {
            this->setMax(1);
        }

        void execute() override {
            for(IExpression* expression : vSubExpressions) {
                if(!expression->isComposite()) {
                    expression->execute();
                    /*const std::unique_ptr<Energyleaf::Stream::V1::Tuple::Entry>& item = static_cast<ExpressionUnit*>(expression)->getEntry().get();
                    if(item->isCastAble(Types::Datatype::DtString::IDENTIFIER)) {
                        this->vValue = item.get()->toString();
                    }*/
                    auto tmp = (static_cast<ExpressionUnit*>(expression))->getEntry().get<Types::Datatype::DtString>();
                    this->vValue = tmp.toString();
                    //this->vValue = (static_cast<ExpressionUnit*>(expression))->getEntry().get<Types::Base::StringItem>().getData();
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
