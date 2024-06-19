#ifndef APALINEA_CORE_TYPE_PIXEL_HSV_HPP
#define APALINEA_CORE_TYPE_PIXEL_HSV_HPP

#include <utility>

namespace Apalinea::Core::Type::Pixel {
    class HSV {
    public:
        HSV() : vH(0.f), vS(0.f), vV(0.f){
        }

        [[maybe_unused]] HSV(const float& h, const float& s, const float& v) : vH(h), vS(s), vV(v) {
        }

        HSV(float&& h, float&& s, float&& v) : vH(h), vS(s), vV(v) {
        }

        HSV(const HSV& other) = default;

        HSV(HSV&& other)  noexcept : vH(other.vH), vS(other.vS), vV(other.vV){
        }

        HSV& operator=(HSV&& other) noexcept {
            this->vH = other.vH;
            this->vS = other.vS;
            this->vV = other.vV;
            return *this;
        }

        HSV& operator=(const HSV& other) = default;

        bool operator == (const HSV& other) const {
            return ((this->vH == other.vH) && (this->vS == other.vS) && (this->vV == other.vV));
        }

        bool operator != (const HSV& other) const {
            return ((this->vH != other.vH) || (this->vS != other.vS) || (this->vV != other.vV));
        }

        [[maybe_unused]] void set(float h, float s, float v) {
            this->vH = h;
            this->vS = s;
            this->vV = v;
        }

        void clear() {
            this->vH = 0.f;
            this->vS = 0.f;
            this->vV = 0.f;
        }

        [[maybe_unused]] [[nodiscard]] bool isEmpty() const {
            return ((this->vH == 0.f) && (this->vS == 0.f) && (this->vV == 0.f));
        }

        [[maybe_unused]] void setH(float&& h) {
            this->vH = std::forward<float>(h);
        }

        [[maybe_unused]] void setH(const float& h) {
            this->vH = h;
        }

        [[nodiscard]] float getH() const {
            return this->vH;
        }

        [[maybe_unused]] void setS(float&& s) {
            this->vS = std::forward<float>(s);
        }

        [[maybe_unused]] void setS(const float& s) {
            this->vS = s;
        }

        [[nodiscard]] float getS() const {
            return this->vS;
        }

        [[maybe_unused]] void setV(float&& v) {
            this->vV = std::forward<float>(v);
        }

        [[maybe_unused]] void setV(const float& v) {
            this->vV = v;
        }

        [[nodiscard]] float getV() const {
            return this->vV;
        }

    private:
        float vH;
        float vS;
        float vV;
    };
} // Apalinea::Core::Type::Pixel

#endif //APALINEA_CORE_TYPE_PIXEL_HSV_HPP
