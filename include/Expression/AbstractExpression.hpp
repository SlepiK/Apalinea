#ifndef APALINEA_EXPRESSION_EXPRESSION_HPP
#define APALINEA_EXPRESSION_EXPRESSION_HPP

#include <list>
#include <utility>
#include "Expression/IExpression.hpp"

namespace Apalinea::Expression {
    class AbstractExpression : public IExpression {
    public:
        explicit AbstractExpression(std::vector<std::string_view> datatypes) : IExpression(std::move(datatypes)){
        }

        ~AbstractExpression() override {
            for(IExpression* exp : vSubExpressions) {
                if(exp != nullptr) {
                    delete exp;
                    exp = nullptr;
                }
            }
        }

        void add(IExpression *expression) override {
            if(this->vSubExpressions.size() <= this->vMax) {
                this->vSubExpressions.push_back(expression);
            } else {
                throw std::runtime_error("Limit of expression already reached!");
            }
        }

        void remove(IExpression *expression) override {
            if(this->vSubExpressions.empty()) {
                throw std::runtime_error("Cant remove expression if no subexpression is known!");
            } else {
                vSubExpressions.remove(expression);
            }
        }

        [[nodiscard]] bool isComposite() const override {
            return true;
        }

        void setTuple(Core::Tuple::Tuple& tuple) override {
            for(IExpression* exp : vSubExpressions) {
                exp->setTuple(tuple);
            }
        }

    private:
        unsigned int vMax = 1;

    protected:
        std::list<IExpression*> vSubExpressions;

        [[maybe_unused]] void setMax(unsigned int max) {
            if(max > 0) this->vMax = max;
            else throw std::runtime_error("Cant set max below 1!");
        }
    };
} // Apalinea::Expression

#endif //APALINEA_EXPRESSION_EXPRESSION_HPP
