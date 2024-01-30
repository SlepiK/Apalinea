//
// Created by SlepiK on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_HSVPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_HSVPIPEOPERATOR_HPP

#include <algorithm>
#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Types/Image/Image.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Pixel/RGB.hpp"
#include "Types/Pixel/HSV.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    class HSVPipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator<Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Pixel::RGB>,
            Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image>> {
    public:
    private:
    protected:
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_HSVPIPEOPERATOR_HPP
