//
// Created by SlepiK on 29.01.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP

#include "Core/Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtString.hpp"
#include "Core/Type/Datatype/DtInt8.hpp"

namespace Apalinea::Operator::SourceOperator {
    class StringDemoSourceOperator
            : public Core::Operator::AbstractSourceOperator {
    public:
    private:
    protected:
        void work(Core::Tuple::Tuple &outputTuple) override {
            outputTuple.clear();
            //outputTuple.addItem(std::string("DemoString"),Type::Datatype::DtString("Hello World"));
            outputTuple.addItem(std::string("DemoString"),Core::Types::Datatype::DtInt8(2));
        }
    };
} // Energyleaf::Stream::V1::Core::Operator::SourceOperator

#endif //STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP
