//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_LINK_LINKTRAIT_HPP
#define STREAM_V1_LINK_LINKTRAIT_HPP

#include <type_traits>
#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Operator/SinkOperator/AbstractSinkOperator.hpp"

namespace Energyleaf::Stream::V1::Link {
    template<typename T>
    struct IsBasedOnAbstractPipeOperator {
        static constexpr bool value = std::is_base_of<Stream::V1::Operator::AbstractPipeOperator<typename T::PipeInputTuple, typename T::PipeOutputTuple>, T>::value;
        using InputTuple = typename T::PipeInputTuple;
        using OutputTuple = typename T::PipeOutputTuple;
    };

    template<typename T>
    struct IsBasedOnAbstractSourceOperator {
        static constexpr bool value = std::is_base_of<Stream::V1::Operator::AbstractSourceOperator<typename T::SourceOutputTuple>, T>::value;
        using OutputTuple = typename T::SourceOutputTuple;
    };

    template<typename T>
    struct IsBasedOnAbstractSinkOperator {
        static constexpr bool value = std::is_base_of<Stream::V1::Operator::AbstractSinkOperator<typename T::SinkInputTuple>, T>::value;
        using InputTuple = typename T::SinkInputTuple;
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_LINKTRAIT_HPP
