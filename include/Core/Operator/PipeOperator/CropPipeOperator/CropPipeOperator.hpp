//
// Created by SlepiK on 29.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_CROPPIPEOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_CROPPIPEOPERATOR_HPP

#include <algorithm>
#include "Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Types/Image/Image.hpp"
#include "Tuple/Tuple.hpp"

namespace Energyleaf::Stream::V1::Core::Operator::PipeOperator {
    class CropPipeOperator
            : public Energyleaf::Stream::V1::Operator::AbstractPipeOperator<Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image>,
                    Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image>> {
    public:
        void setSize(int x, int width, int y, int height) {
            this->vX = x;
            this->vWidth = width;
            this->vY = y;
            this->vHeight = height;
        }
    private:
        int vX = 0;
        int vWidth = 0;
        int vY = 0;
        int vHeight = 0;
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image> &inputTuple,
                  Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Image> &outputTuple) override {
            Energyleaf::Stream::V1::Types::Image img = inputTuple.getItem<Energyleaf::Stream::V1::Types::Image>(0).getData();


            if (this->vX < 0 || this->vWidth <= 0 || this->vX + this->vWidth > img.getWidth() ||
                this->vY < 0 || this->vHeight <= 0 || this->vY + this->vHeight > img.getHeight()) {
                return;
            }

            Energyleaf::Stream::V1::Types::Image outImg(this->vWidth,this->vHeight,img.getBytesPerPixel(),img.getFormat(),
                                                        new uint8_t[this->vWidth * this->vHeight * img.getBytesPerPixel()]);

            int startIdxX = this->vX * img.getBytesPerPixel();

            int bytesPerRow = this->vWidth * img.getBytesPerPixel();

            for (int y = 0; y < this->vHeight; ++y) {
                int inIdx = startIdxX + (y + this->vY) * img.getWidth() * img.getBytesPerPixel();
                int outIdx = y * bytesPerRow;

                std::copy(img.getData() + inIdx, img.getData() + inIdx + bytesPerRow, outImg.getData() + outIdx);
            }

            outputTuple.clear();
            outputTuple.addItem(std::string("Image"),outImg);
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_PIPEOPERATOR_CROPPIPEOPERATOR_HPP
