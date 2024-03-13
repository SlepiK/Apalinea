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
#include "Types/Datatype/DtInt8.hpp"
#include "Types/Datatype/DtInt16.hpp"
#include "Types/Datatype/DtInt32.hpp"
#include "Types/Datatype/DtInt64.hpp"
#include "Types/Datatype/DtInt.hpp"
#include "Types/Datatype/DtUInt8.hpp"
#include "Types/Datatype/DtUInt16.hpp"
#include "Types/Datatype/DtUInt32.hpp"
#include "Types/Datatype/DtUInt64.hpp"
#include "Types/Datatype/DtSizeT.hpp"

namespace Energyleaf::Stream::V1::Expression {
    class ToDtStringExpression : public Expression {
    public:
        static constexpr std::string_view IDENTIFIER = Types::Datatype::DtString::IDENTIFIER;

        ToDtStringExpression() : Expression({Types::Datatype::DtInt8::IDENTIFIER,Types::Datatype::DtInt16::IDENTIFIER,Types::Datatype::DtInt32::IDENTIFIER,
                                             Types::Datatype::DtInt64::IDENTIFIER,Types::Datatype::DtInt::IDENTIFIER,Types::Datatype::DtUInt8::IDENTIFIER,
                                             Types::Datatype::DtUInt16::IDENTIFIER,Types::Datatype::DtUInt32::IDENTIFIER,Types::Datatype::DtUInt64::IDENTIFIER,
                                             Types::Datatype::DtSizeT::IDENTIFIER}) {
        }

        void execute() override {
            if(vSubExpressions.size() > 1) {
                throw std::runtime_error("A expression for a single sub expression, cant be executed on more then a single sub expression!");
            }
            if(vSubExpressions.empty()) {
                throw std::runtime_error("A expression can be empty!");
            }

            IExpression* exp = vSubExpressions.front();
            std::string_view expIdentifier = exp->getIdentifier();
            if(!this->isDatatypeAllowed(expIdentifier)) {
                throw std::runtime_error("The datatype returned from the given expression is not allowed!");
            }

            

            const Types::Datatype::IDt& expData = exp->getData();


            for(IExpression* expression : vSubExpressions) {
                if(!expression->isComposite()) {
                    expression->execute();

                    auto tmpData = (static_cast<ExpressionUnit*>(expression)).
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

        const Types::Datatype::IDt& getData() const override {
            return this->data;
        }

        std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }
    private:
        Types::Datatype::DtString data;
    };
}

#endif //STREAM_V1_EXPRESSION_TOEXPRESSION_TOSTRING_HPP
