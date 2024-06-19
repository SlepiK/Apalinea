#ifndef APALINEA_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP
#define APALINEA_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP

#include "Core/Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtString.hpp"
#include "Core/Type/Datatype/DtInt8.hpp"

namespace Apalinea::Operator::SourceOperator {
    class StringDemoSourceOperator
            : public Core::Operator::AbstractSourceOperator {
    protected:
        void work(Core::Tuple::Tuple &outputTuple) override {
            outputTuple.clear();
            //outputTuple.addItem(std::string("DemoString"),Type::Datatype::DtString("Hello World"));
            outputTuple.addItem(std::string("DemoString"),Core::Type::Datatype::DtInt8(2));
        }
    };
} // Apalinea::Operator::SourceOperator

#endif //APALINEA_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP
