//
// Created by SlepiK on 16.02.2024.
//

#ifndef STREAM_V1_TUPLE_IEVALUATE_HPP
#define STREAM_V1_TUPLE_IEVALUATE_HPP

namespace Energyleaf::Stream::V1::Tuple {
    class IEvaluate {
    public:
        virtual ~IEvaluate() = default;
        virtual void evaluate() = 0;
    };
}

#endif //STREAM_V1_TUPLE_IEVALUATE_HPP
