//
// Created by SlepiK on 02.02.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATORTRAIT_HPP
#define STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATORTRAIT_HPP

#include <type_traits>
#include "Extras/Vision/Camera/AbstractCamera.hpp"

namespace Apalinea::Operator::SourceOperator::Trait {
    template<typename T>
    struct IsBasedOnAbstractCamera {
        static constexpr bool value = std::is_base_of<Extras::Vision::AbstractCamera<typename T::CameraConfig>, T>::value;
        using CameraConfig = typename T::CameraConfig;
    };
} // Energyleaf::Stream::V1::Core::Operator::SourceOperator

#endif //STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATORTRAIT_HPP
