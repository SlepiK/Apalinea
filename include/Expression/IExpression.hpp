#ifndef APALINEA_EXPRESSION_IEXPRESSION_HPP
#define APALINEA_EXPRESSION_IEXPRESSION_HPP

#include <stdexcept>
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/IDt.hpp"
#include "Core/Type/Datatype/DtRegistry.hpp"

namespace Apalinea::Expression {
    class IExpression {
    public:
        explicit IExpression(std::vector<std::string_view> datatypes) : datatypes(datatypes.begin(),datatypes.end()), used(false){
        }

        virtual ~IExpression() = default;

        virtual void add(IExpression *component) {
            throw std::runtime_error("Operation is not direct supported!");
        }

        [[maybe_unused]] virtual void remove(IExpression *component) {
            throw std::runtime_error("Operation is not direct supported!");
        }

        [[nodiscard]] virtual bool isComposite() const = 0;

        virtual void execute() = 0;

        [[nodiscard]] bool isDatatypeAllowed(std::string_view datatype) const {
            if(datatype == Core::Type::Datatype::UNDEFINED) return true;
            return this->datatypes.find(datatype) != this->datatypes.end();
        }

        [[nodiscard]] virtual const Core::Type::Datatype::IDt& getData() const = 0;

        [[nodiscard]] virtual std::string_view getIdentifier() const = 0;

        virtual void setTuple(Core::Tuple::Tuple& inputTupel) = 0;

        void setUsed(bool use) {
            this->used = use;
        }

        [[nodiscard]] bool isUsed() const {
            return this->used;
        }

    private:
        bool used;
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
} // Apalinea::Expression

#endif //APALINEA_EXPRESSION_IEXPRESSION_HPP
