//
// Created by SlepiK on 02.02.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP

#include "Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Image/Image.hpp"
#include "CameraSourceOperatorTrait.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::SourceOperator {
    template<typename Camera>
    class CameraSourceOperator
            : public Energyleaf::Stream::V1::Operator::AbstractSourceOperator<Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image>> {
        static_assert(Trait::IsBasedOnAbstractCamera<Camera>::value,"Camera needs to be derived from AbstractCamera!");
    public:
        using CameraConfig = typename Trait::IsBasedOnAbstractCamera<Camera>::CameraConfig;

        CameraSourceOperator() : vCamera() {
        }

        const Camera& getCamera() const{
            return this->vCamera;
        }

        void setCameraConfig(CameraConfig& config) {
            this->vCamera.setConfig(config);
        }

        void setCameraConfig(CameraConfig&& config) {
            this->vCamera.setConfig(config);
        }

        const CameraConfig& getCameraConfig() const {
            this->vCamera.getConfig();
        }


    private:
        Camera vCamera;
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image> &outputTuple) override {
            outputTuple.clear();
            outputTuple.addItem(std::string("Image"),this->vCamera.getImage());
        }
    };
} // Energyleaf::Stream::V1::Core::Operator::SourceOperator


#endif //STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP
