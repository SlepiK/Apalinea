//
// Created by SlepiK on 29.01.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP

#include "Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Tuple/Tuple.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::SourceOperator {
    class StringDemoSourceOperator
            : public Energyleaf::Stream::V1::Operator::AbstractSourceOperator<Energyleaf::Stream::V1::Tuple::Tuple<std::string>> {
    public:
    private:
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<std::string> &outputTuple) override {
            outputTuple.clear();
            outputTuple.addItem(std::string("DemoString"),std::string("Hello World"));
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_STRINGDEMOSOURCEOPERATOR_HPP
