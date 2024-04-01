//
// Created by Simon Stahmer on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_DETECTORPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_DETECTORPIPEOPERATOR_HPP

#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Image/Image.hpp"
#include "Types/Pixel/HSV.hpp"
#include "Types/Pixel/RGB.hpp"
#include "Extras/Converter/Types/Pixel/RGBtoHSV.hpp"
#include <utility>
#include "Types/Datatype/DtSizeT.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    class DetectorPipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator {
    public:
        void setLowerBorder(Energyleaf::Stream::V1::Types::Pixel::HSV&& hsv) {
            this->vLowerBorder = hsv;
        }

        void setHigherBorder(Energyleaf::Stream::V1::Types::Pixel::HSV&& hsv) {
            this->vHigherBorder = hsv;
        }

        const Energyleaf::Stream::V1::Types::Pixel::HSV& getLowerBorder() {
            return this->vLowerBorder;
        }

        const Energyleaf::Stream::V1::Types::Pixel::HSV& getHigherBorder() {
            return this->vHigherBorder;
        }
    private:
        Energyleaf::Stream::V1::Types::Pixel::HSV vLowerBorder = Energyleaf::Stream::V1::Types::Pixel::HSV(0.f,0.f,0.f);
        Energyleaf::Stream::V1::Types::Pixel::HSV vHigherBorder = Energyleaf::Stream::V1::Types::Pixel::HSV(0.f,0.f,0.f);;
    protected:
        void work(Tuple::Tuple &inputTuple,
                  Tuple::Tuple &outputTuple) override {
            std::size_t foundPixel = 0;

            Energyleaf::Stream::V1::Types::Image image;// = inputTuple.getItem<Energyleaf::Stream::V1::Types::Image>(1).getData();
            Energyleaf::Stream::V1::Types::Pixel::HSV hsv;
            for (std::size_t i = 0; i < (image.getWidth() * image.getHeight()); ++i) {
                std::size_t index = i * image.getBytesPerPixel();
                // Convert RGB to HSV

                Energyleaf::Stream::V1::Extras::Converter::Types::Pixel::RGBtoHSV::convert(Energyleaf::Stream::V1::Types::Pixel::RGB(image.getData()[index],image.getData()[index+1],image.getData()[index+2]),hsv);

                // Check if the pixel is in the red color range in HSV space
                if ((hsv.getH() >= this->vLowerBorder.getH() && hsv.getH() <= this->vHigherBorder.getH()) &&
                    (hsv.getS() >= this->vLowerBorder.getS() && hsv.getS() <= this->vHigherBorder.getS()) &&
                    (hsv.getV() >= this->vLowerBorder.getV() && hsv.getV() <= this->vHigherBorder.getV())) {
                    ++foundPixel;
                }
            }

            outputTuple.clear();
            outputTuple.addItem(std::string("FOUNDPIXEL"),Types::Datatype::DtSizeT(foundPixel));
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_DETECTORPIPEOPERATOR_HPP
