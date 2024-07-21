#ifndef APALINEA_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP
#define APALINEA_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP

#include "Core/Operator/SourceOperator/AbstractSourceOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Operator/SourceOperator/CameraSourceOperator/CameraSourceOperatorTrait.hpp"
#include "Core/Type/Image/Image.hpp"
#include "Core/Type/Datatype/DtImage.hpp"

namespace Apalinea::Operator::SourceOperator {
    template<typename Camera>
    class [[maybe_unused]] CameraSourceOperator
            : public Core::Operator::AbstractSourceOperator {
        static_assert(Trait::IsBasedOnAbstractCamera<Camera>::value,"Camera needs to be derived from AbstractCamera!");
    public:
        using CameraConfig = typename Trait::IsBasedOnAbstractCamera<Camera>::CameraConfig;

        CameraSourceOperator() : vCamera() {
        }

        ~CameraSourceOperator() override = default;

        [[maybe_unused]] const Camera& getCamera() const{
            return this->vCamera;
        }

        [[maybe_unused]] void setCameraConfig(CameraConfig& config) {
            this->vCamera.setConfig(config);
        }

        [[maybe_unused]] void setCameraConfig(CameraConfig&& config) {
            this->vCamera.setConfig(config);
        }

        [[maybe_unused]] const CameraConfig& getCameraConfig() const {
            this->vCamera.getConfig();
        }

        void start() {
            this->vCamera.start();
        }

    private:
        Camera vCamera;

    protected:
        void work(Core::Tuple::Tuple &outputTuple) override {
            Core::Type::Image img = this->vCamera.getImage();
            if(img.getData() != nullptr) {
                outputTuple.clear();
                outputTuple.addItem(std::string("Image"),Core::Type::Datatype::DtImage(img));
                vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
            } else {
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR,Core::Log::getFilename(__FILE__),__LINE__,"No image-data available!");
                vProcessState = Core::Operator::OperatorProcessState::BREAK;
            }
        }
    };
} // Apalinea::Operator::SourceOperator


#endif //APALINEA_OPERATOR_SOURCEOPERATOR_CAMERASOURCEOPERATOR_HPP
