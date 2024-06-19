//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXPRESSION_DATATYPE_DTUINT32EXPRESSION_HPP
#define STREAM_V1_EXPRESSION_DATATYPE_DTUINT32EXPRESSION_HPP

#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtUInt32.hpp"
#include "Expression/IExpression.hpp"

namespace Apalinea::Expression::DataType {
    class DtUInt32Expression : public IExpression {
    public:
        static constexpr std::string_view IDENTIFIER = Core::Types::Datatype::DtUInt32::IDENTIFIER;

        explicit DtUInt32Expression(std::string&& entry, bool load = true) : IExpression({IDENTIFIER}), entry(std::move(entry)), load(load) {
        }

        explicit DtUInt32Expression(uint32_t&& value) : IExpression({IDENTIFIER}), load(false), data(value) {
        }

        ~DtUInt32Expression() override = default;

        [[nodiscard]] bool isComposite() const override {
            return false;
        }

        void setTuple(Core::Tuple::Tuple& tuple) override {
            if(load) {
                this->tuple = tuple;
            }
        }

        [[nodiscard]] const Core::Types::Datatype::IDt& getData() const override {
            return this->data;
        }

        void execute() override {
            if(this->tuple.getItems().empty()) {
                throw std::runtime_error("Tuple is empty!");
            }

            if(this->tuple.containsItem(this->entry)) {
                this->data = this->tuple.getEntry(this->entry).get<Core::Types::Datatype::DtUInt32>();
            } else {
                throw std::runtime_error("Entry was not found in the given tuple!");
            }
        }

        [[nodiscard]] std::string_view getIdentifier() const override {
            return IDENTIFIER;
        }
    private:
        Core::Tuple::Tuple tuple;
        std::string entry;
        Core::Types::Datatype::DtUInt32 data;
        bool load;
    };
}

#endif //STREAM_V1_EXPRESSION_DATATYPE_DTUINT32EXPRESSION_HPP
