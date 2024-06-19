#ifndef APALINEA_CORE_TYPE_PIXEL_RGB_HPP
#define APALINEA_CORE_TYPE_PIXEL_RGB_HPP

#include <utility>

namespace Apalinea::Core::Type::Pixel {
    class RGB {
    public:
        RGB() : vR(0), vG(0), vB(0){
        }

        [[maybe_unused]] RGB(const int& r, const int& g, const int& b) : vR(r), vG(g), vB(b) {
        }

        RGB(int&& r, int&& g, int&& b) : vR(r), vG(g), vB(b) {
        }

        RGB(const RGB& other) = default;

        RGB(RGB&& other)  noexcept : vR(other.vR), vG(other.vG), vB(other.vB){
        }

        RGB& operator=(RGB&& other) noexcept {
            this->vR = other.vR;
            this->vG = other.vG;
            this->vB = other.vB;
            return *this;
        }

        RGB& operator=(const RGB& other) = default;

        bool operator == (const RGB& other) const {
            return ((this->vR == other.vR) && (this->vG == other.vG) && (this->vB == other.vB));
        }

        bool operator != (const RGB& other) const {
            return ((this->vR != other.vR) || (this->vG != other.vG) || (this->vB != other.vB));
        }

        [[maybe_unused]] void set(int r, int g, int b) {
            this->vR = r;
            this->vG = g;
            this->vB = b;
        }

        void clear() {
            this->vR = 0;
            this->vG = 0;
            this->vB = 0;
        }

        [[maybe_unused]] [[nodiscard]] bool isEmpty() const {
            return ((this->vR == 0) && (this->vG == 0) && (this->vB == 0));
        }

        [[maybe_unused]] void setR(int&& r) {
            this->vR = std::forward<int>(r);
        }

        [[maybe_unused]] void setR(const int& r) {
            this->vR = r;
        }

        [[maybe_unused]] [[nodiscard]] int getR() const {
            return this->vR;
        }

        [[maybe_unused]] void setG(int&& g) {
            this->vG = std::forward<int>(g);
        }

        [[maybe_unused]] void setG(const int& g) {
            this->vG = g;
        }

        [[maybe_unused]] [[nodiscard]] int getG() const {
            return this->vG;
        }

        [[maybe_unused]] void setB(int&& b) {
            this->vB = std::forward<int>(b);
        }

        [[maybe_unused]] void setB(const int& b) {
            this->vB = b;
        }

        [[maybe_unused]] [[nodiscard]] int getB() const {
            return this->vB;
        }

    private:
        int vR;
        int vG;
        int vB;
    };
} // Apalinea::Core::Type::Pixel

#endif //APALINEA_CORE_TYPE_PIXEL_RGB_HPP