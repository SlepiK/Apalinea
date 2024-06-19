//
// Created by SlepiK on 02.02.2024.
//

#ifndef STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP

#include "Core/Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Operator/SourceOperator/CameraSourceOperator/CameraSourceOperatorTrait.hpp"
#include "Core/Type/Image/Image.hpp"
#include "Core/Type/Datatype/DtImage.hpp"

namespace Apalinea::Operator::SourceOperator {
    template<typename Camera>
    class CameraSourceOperator
            : public Core::Operator::AbstractSourceOperator {
        static_assert(Trait::IsBasedOnAbstractCamera<Camera>::value,"Camera needs to be derived from AbstractCamera!");
    public:
        using CameraConfig = typename Trait::IsBasedOnAbstractCamera<Camera>::CameraConfig;

        CameraSourceOperator() : vCamera() {
        }

        ~CameraSourceOperator() = default;

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

        void start() {
            this->vCamera.start();
        }


    private:
        Camera vCamera;
    protected:
        void work(Core::Tuple::Tuple &outputTuple) override {
            Core::Types::Image img = this->vCamera.getImage();
            if(img.getData() != nullptr) {
                outputTuple.clear();
                outputTuple.addItem(std::string("Image"),Core::Types::Datatype::DtImage(img));
                vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
            } else {
                vProcessState = Core::Operator::OperatorProcessState::BREAK;
            }
        }
    };
} // Energyleaf::Stream::V1::Core::Operator::SourceOperator


#endif //STREAM_V1_CORE_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP
