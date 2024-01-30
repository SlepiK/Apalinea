//
// Created by SlepiK on 29.01.24.
//

#ifndef ENERGYLEAF_STREAM_V1_TYPES_IMAGE_HPP
#define ENERGYLEAF_STREAM_V1_TYPES_IMAGE_HPP

#include <cstdint>
#include <utility>
#include "ImageFormat.hpp"

namespace Energyleaf::Stream::V1::Types {

    class Image {
    public:
        Image()
            : vWidth(0), vHeight(0), vBytesPerPixel(0), vFormat(ImageFormat::FB_RGB888), vData(nullptr){
        };

        Image(int width, int height, int bytesPerPixel, ImageFormat format, std::uint8_t* data)
            : vWidth(width), vHeight(height), vBytesPerPixel(bytesPerPixel), vFormat(format), vData(data) {
        }

        Image(Image &&other)
        noexcept: vWidth(other.vWidth), vHeight(other.vHeight), vBytesPerPixel(other.vBytesPerPixel), vFormat(other.vFormat), vData(other.vData) {
        }

        Image(const Image& other) {
            this->vWidth = other.vWidth;
            this->vHeight = other.vHeight;
            this->vBytesPerPixel = other.vBytesPerPixel;
            this->vFormat = other.vFormat;
            this->vData = other.vData;
        }

#ifdef ENERGYLEAF_ESP
        explicit Image(fb_data_t watt)
                : vWidth(watt.width), vHeight(watt.height), vBytesPerPixel(watt.bytes_per_pixel), vFormat(
                static_cast<ImageFormat>(watt.format)), vData(watt.data) {
        }

        explicit Image(fb_data_t&& watt)
                : vWidth(watt.width), vHeight(watt.height), vBytesPerPixel(watt.bytes_per_pixel), vFormat(
                static_cast<ImageFormat>(watt.format)), vData(watt.data){
        }
#endif

        Image& operator=(Image&& other) noexcept {
            this->vWidth = other.vWidth;
            this->vHeight = other.vHeight;
            this->vBytesPerPixel = other.vBytesPerPixel;
            this->vFormat = other.vFormat;
            this->vData = other.vData;
            return *this;
        }

        Image& operator=(const Image& other) {
            this->vWidth = other.vWidth;
            this->vHeight = other.vHeight;
            this->vBytesPerPixel = other.vBytesPerPixel;
            this->vFormat = other.vFormat;
            this->vData = other.vData;
            return *this;
        }

        virtual ~Image() {
            if(this->vData) {
                delete this->vData;
                this->vData = nullptr;
            }
        }

        [[nodiscard]] int getWidth() const {
            return this->vWidth;
        }

        [[nodiscard]] int getHeight() const {
            return this->vHeight;
        }

        [[nodiscard]] int getBytesPerPixel() const {
            return this->vBytesPerPixel;
        }

        [[nodiscard]] ImageFormat getFormat() const {
            return this->vFormat;
        }

        std::uint8_t* getData() {
            return this->vData;
        }

        void setWidth(int width) {
            this->vWidth = width;
        }

        void setHeight(int height) {
            this->vHeight = height;
        }

        void setBytesPerPixel(int bytesPerPixel) {
            this->vBytesPerPixel = bytesPerPixel;
        }

        void setFormat(ImageFormat format) {
            this->vFormat = format;
        }

    private:
        int vWidth;
        int vHeight;
        int vBytesPerPixel;
        ImageFormat vFormat;
        std::uint8_t* vData;
    };
}
#endif //ENERGYLEAF_STREAM_V1_TYPES_IMAGE_HPP