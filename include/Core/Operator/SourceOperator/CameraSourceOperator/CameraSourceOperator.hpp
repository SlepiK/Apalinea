//
// Created by SlepiK on 02.02.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP

#include "Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Image/Image.hpp"
#include "Extras/Vision/Camera/AbstractCamera.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::SourceOperator {
    class StringDemoSourceOperator
            : public Energyleaf::Stream::V1::Operator::AbstractSourceOperator<Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image>> {
    public:
    private:
        Energyleaf::Stream::V1::Extras::Vision::AbstractCamera camera;
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image> &outputTuple) override {
            outputTuple.clear();
            //outputTuple.addItem(std::string("DemoString"),std::string("Hello World"));
        }
    };
} // Energyleaf::Stream::V1::Core::Operator::SourceOperator


#endif //STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP
