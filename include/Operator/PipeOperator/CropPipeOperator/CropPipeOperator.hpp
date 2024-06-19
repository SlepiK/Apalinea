#ifndef APALINEA_OPERATOR_PIPEOPERATOR_CROPPIPEOPERATOR_HPP
#define APALINEA_OPERATOR_PIPEOPERATOR_CROPPIPEOPERATOR_HPP

#include <algorithm>
#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Image/Image.hpp"
#include "Core/Type/Datatype/DtImage.hpp"
#include "Core/Type/Datatype/DtInt.hpp"

namespace Apalinea::Operator::PipeOperator {
    class CropPipeOperator
            : public Core::Operator::AbstractPipeOperator {
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
        void work(Core::Tuple::Tuple &inputTuple,
                  Core::Tuple::Tuple &outputTuple) override {
            if(!inputTuple.containsItem("Image")){
                vProcessState = Core::Operator::OperatorProcessState::BREAK;
                return;
            } else {
                vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
            }
            Core::Type::Image img = inputTuple.getItem<Core::Type::Datatype::DtImage>("Image").toImage();
            inputTuple.removeItem("Image");

            if (this->vX < 0 || this->vWidth <= 0 || this->vX + this->vWidth > img.getWidth() ||
                this->vY < 0 || this->vHeight <= 0 || this->vY + this->vHeight > img.getHeight()) {
                return;
            }

            Core::Type::Image outImg(this->vWidth, this->vHeight, img.getBytesPerPixel(), img.getFormat());

            int startIdxX = this->vX * img.getBytesPerPixel();

            int bytesPerRow = this->vWidth * img.getBytesPerPixel();

            for (int y = 0; y < this->vHeight; ++y) {
                int inIdx = startIdxX + (y + this->vY) * img.getWidth() * img.getBytesPerPixel();
                int outIdx = y * bytesPerRow;

                std::copy(img.getData() + inIdx, img.getData() + inIdx + bytesPerRow, outImg.getData() + outIdx);
            }

            outputTuple.clear();
            outputTuple.moveItems(std::move(inputTuple));
            outputTuple.addItem(std::string("Image"),Core::Type::Datatype::DtImage(outImg));
        }
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_CROPPIPEOPERATOR_HPP
