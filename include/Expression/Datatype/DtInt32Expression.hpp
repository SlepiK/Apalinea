#ifndef APALINEA_EXPRESSION_DATATYPE_DTINT32EXPRESSION_HPP
#define APALINEA_EXPRESSION_DATATYPE_DTINT32EXPRESSION_HPP

#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtInt32.hpp"
#include "Expression/IExpression.hpp"

namespace Apalinea::Expression::DataType {
    class [[maybe_unused]] DtInt32Expression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Type::Datatype::DtInt32::IDENTIFIER;

        [[maybe_unused]] explicit DtInt32Expression(std::string&& entry) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(true) {
        }

        [[maybe_unused]] explicit DtInt32Expression(int32_t&& value) : IExpression({IDENTIFIER}), load(false), data(value) {
        }

        ~DtInt32Expression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Core::Tuple::Tuple& inputTupel) override {
            if(load) {
                this->tuple = inputTupel;
            }
        }

        [[nodiscard]] const Core::Type::Datatype::IDt& getData() const override {
            return this->data;
        }

        void execute() override {
            if(load) {
                if (this->tuple.getItems().empty()) {
                    throw std::runtime_error("Tuple is empty!");
                }

                if (this->tuple.containsItem(this->entry)) {
                    this->data = this->tuple.getEntry(this->entry).get<Core::Type::Datatype::DtInt32>();
                } else {
                    throw std::runtime_error("Entry was not found in the given tuple!");
                }
            }
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }

    private:
        Core::Tuple::Tuple tuple;
        std::string entry;
        Core::Type::Datatype::DtInt32 data;
        bool load;
    };
} // Apalinea::Expression::DataType

#endif //APALINEA_EXPRESSION_DATATYPE_DTINT32EXPRESSION_HPP
