//
// Created by SlepiK on 29.01.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP

#include "Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Tuple/Tuple.hpp"
#include <Types/Datatype/DtString.hpp>
#include <Types/Datatype/DtInt8.hpp>

namespace Energyleaf::Stream::V1::Core::Operator::SourceOperator {
    class StringDemoSourceOperator
            : public Energyleaf::Stream::V1::Operator::AbstractSourceOperator {
    public:
    private:
    protected:
        void work(Tuple::Tuple &outputTuple) override {
            outputTuple.clear();
            //outputTuple.addItem(std::string("DemoString"),Types::Datatype::DtString("Hello World"));
            outputTuple.addItem(std::string("DemoString"),Types::Datatype::DtInt8(2));
            //outputTuple.addItem(std::string("DemoString"),std::string("Hello World"));
        }
    };
} // Energyleaf::Stream::V1::Core::Operator::SourceOperator

#endif //STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP
