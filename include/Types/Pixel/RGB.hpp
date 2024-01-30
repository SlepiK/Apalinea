//
// Created by SlepiK on 30.01.24.
//

#ifndef ENERGYLEAF_STREAM_V1_TYPES_PIXEL_RGB_HPP
#define ENERGYLEAF_STREAM_V1_TYPES_PIXEL_RGB_HPP

#include <utility>

namespace Energyleaf::Stream::V1::Types::Pixel {
    class RGB {
    public:
        RGB() : vR(0), vG(0), vB(0){
        }

        RGB(const int& r, const int& g, const int& b) : vR(r), vG(g), vB(b) {
        }

        RGB(int&& r, int&& g, int&& b) : vR(r), vG(g), vB(b) {
        }

        RGB(const RGB& other) : vR(other.vR), vG(other.vG), vB(other.vB){
        }

        RGB(RGB&& other)  noexcept : vR(other.vR), vG(other.vG), vB(other.vB){
        }

        RGB& operator=(RGB&& other) noexcept {
            this->vR = other.vR;
            this->vG = other.vG;
            this->vB = other.vB;
            return *this;
        }

        RGB& operator=(const RGB& other) {
            this->vR = other.vR;
            this->vG = other.vG;
            this->vB = other.vB;
            return *this;
        }

        bool operator == (const RGB& other) const {
            return ((this->vR == other.vR) && (this->vG == other.vG) && (this->vB == other.vB));
        }

        bool operator != (const RGB& other) const {
            return ((this->vR != other.vR) || (this->vG != other.vG) || (this->vB != other.vB));
        }

        void set(int r, int g, int b) {
            this->vR = r;
            this->vG = g;
            this->vB = b;
        }

        void clear() {
            this->vR = 0;
            this->vG = 0;
            this->vB = 0;
        }

        [[nodiscard]] bool isEmpty() const {
            return ((this->vR == 0) && (this->vG == 0) && (this->vB == 0));
        }

        void setR(int&& r) {
            this->vR = std::forward<int>(r);
        }

        void setR(const int& r) {
            this->vR = r;
        }

        [[nodiscard]] int getR() const {
            return this->vR;
        }

        void setG(int&& g) {
            this->vG = std::forward<int>(g);
        }

        void setG(const int& g) {
            this->vG = g;
        }

        [[nodiscard]] int getG() const {
            return this->vG;
        }

        void setB(int&& b) {
            this->vB = std::forward<int>(b);
        }

        void setB(const int& b) {
            this->vB = b;
        }

        [[nodiscard]] int getB() const {
            return this->vB;
        }
    private:
        int vR;
        int vG;
        int vB;
    };
}

#endif //ENERGYLEAF_STREAM_V1_TYPES_PIXEL_RGB_HPP