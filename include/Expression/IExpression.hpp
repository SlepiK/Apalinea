//
// Created by SlepiK on 19.02.24.
//

#ifndef STREAM_V1_EXPRESSION_IEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_IEXPRESSION_HPP

#include <stdexcept>
#include <Types/Datatype/IDt.hpp>

namespace Energyleaf::Stream::V1::Expression {
    class IExpression {
    public:
        explicit IExpression(std::vector<std::string_view> datatypes) : datatypes(datatypes.begin(),datatypes.end()){
        }

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

        bool isDatatypeAllowed(std::string_view datatype) const {
            return this->datatypes.find(datatype) != this->datatypes.end();
        }

        virtual const Types::Datatype::IDt& getData() const = 0;
        virtual std::string_view getIdentifier() const = 0;
    protected:
        IExpression *vHeadExpression{};
    private:
        const std::unordered_set<std::string_view> datatypes;
    };
}

#endif //STREAM_V1_EXPRESSION_IEXPRESSION_HPP
