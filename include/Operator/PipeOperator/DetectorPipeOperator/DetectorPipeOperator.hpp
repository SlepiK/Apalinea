//
// Created by Simon Stahmer on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_DETECTORPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_DETECTORPIPEOPERATOR_HPP

#include <utility>
#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Image/Image.hpp"
#include "Core/Type/Pixel/HSV.hpp"
#include "Core/Type/Pixel/RGB.hpp"
#include "Core/Type/Datatype/DtSizeT.hpp"
#include "Core/Type/Datatype/DtImage.hpp"
#include "Extras/Converter/Types/Pixel/RGBtoHSV.hpp"

namespace Apalinea::Operator::PipeOperator {
    class DetectorPipeOperator
            : public Core::Operator::AbstractPipeOperator {
    public:
        void setLowerBorder(Core::Types::Pixel::HSV&& hsv) {
            this->vLowerBorder = hsv;
        }

        void setHigherBorder(Core::Types::Pixel::HSV&& hsv) {
            this->vHigherBorder = hsv;
        }

        const Core::Types::Pixel::HSV& getLowerBorder() {
            return this->vLowerBorder;
        }

        const Core::Types::Pixel::HSV& getHigherBorder() {
            return this->vHigherBorder;
        }
    private:
        Core::Types::Pixel::HSV vLowerBorder = Core::Types::Pixel::HSV(0.f,0.f,0.f);
        Core::Types::Pixel::HSV vHigherBorder = Core::Types::Pixel::HSV(0.f,0.f,0.f);;
    protected:
        void work(Core::Tuple::Tuple &inputTuple,
                  Core::Tuple::Tuple &outputTuple) override {
            if(!inputTuple.containsItem("Image")){
                vProcessState = Core::Operator::OperatorProcessState::BREAK;
                return;
            } else {
                vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
            }
            Core::Types::Image image = inputTuple.getItem<Core::Types::Datatype::DtImage>("Image").toImage();
            inputTuple.removeItem("Image");

            std::size_t foundPixel = 0;
            Core::Types::Pixel::HSV hsv;
            for (std::size_t i = 0; i < (image.getWidth() * image.getHeight()); ++i) {
                std::size_t index = i * image.getBytesPerPixel();
                // Convert RGB to HSV

                Extras::Converter::Types::Pixel::RGBtoHSV::convert(Core::Types::Pixel::RGB(image.getData()[index],image.getData()[index+1],image.getData()[index+2]),hsv);

                // Check if the pixel is in the red color range in HSV space
                if ((hsv.getH() >= this->vLowerBorder.getH() && hsv.getH() <= this->vHigherBorder.getH()) &&
                    (hsv.getS() >= this->vLowerBorder.getS() && hsv.getS() <= this->vHigherBorder.getS()) &&
                    (hsv.getV() >= this->vLowerBorder.getV() && hsv.getV() <= this->vHigherBorder.getV())) {
                    ++foundPixel;
                }
            }

            outputTuple.clear();
            outputTuple.moveItems(std::move(inputTuple));
            outputTuple.addItem(std::string("FOUNDPIXEL"),Core::Types::Datatype::DtSizeT(foundPixel));
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_DETECTORPIPEOPERATOR_HPP
