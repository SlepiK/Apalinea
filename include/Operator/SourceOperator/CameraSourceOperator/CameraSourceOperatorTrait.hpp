#ifndef APALINEA_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATORTRAIT_HPP
#define APALINEA_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATORTRAIT_HPP

#include <type_traits>
#include "Extras/Vision/Camera/AbstractCamera.hpp"

namespace Apalinea::Operator::SourceOperator::Trait {
    template<typename T>
    struct IsBasedOnAbstractCamera {
        static constexpr bool value = std::is_base_of<Extras::Vision::AbstractCamera<typename T::CameraConfig>, T>::value;
        using CameraConfig = typename T::CameraConfig;
    };
} // Apalinea::Operator::SourceOperator

#endif //APALINEA_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATORTRAIT_HPP
