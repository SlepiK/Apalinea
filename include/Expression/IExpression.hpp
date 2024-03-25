//
// Created by SlepiK on 19.02.24.
//

#ifndef STREAM_V1_EXPRESSION_IEXPRESSION_HPP
#define STREAM_V1_EXPRESSION_IEXPRESSION_HPP

#include <stdexcept>
#include <Types/Datatype/IDt.hpp>
#include <Types/Datatype/DtRegistry.hpp>

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

        [[nodiscard]] bool isDatatypeAllowed(std::string_view datatype) const {
            if(datatype == Types::Datatype::UNDEFINED) return true;
            return this->datatypes.find(datatype) != this->datatypes.end();
        }

        [[nodiscard]] virtual const Types::Datatype::IDt& getData() const = 0;

        [[nodiscard]] virtual std::string_view getIdentifier() const = 0;
    protected:
        IExpression *vHeadExpression{};
    private:
        const std::unordered_set<std::string_view> datatypes;
    };

    template<typename T>
    [[nodiscard]] static const T& getData(IExpression* expression) {
        if(expression->getIdentifier() == T::IDENTIFIER) {
            return static_cast<const T&>(expression->getData());
        } else {
            throw std::runtime_error("Not allowed!");
        }
    }
}

#endif //STREAM_V1_EXPRESSION_IEXPRESSION_HPP
