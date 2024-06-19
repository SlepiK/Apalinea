#ifndef APALINEA_CORE_TYPE_WINDOWID_HPP
#define APALINEA_CORE_TYPE_WINDOWID_HPP

#include <utility>
#include <cstddef>

namespace Apalinea::Core::Type {
    class WindowId {
    public:

        explicit WindowId()
                : id(0) {
        }

        explicit WindowId(std::size_t id)
                : id(id) {
        }

        explicit WindowId(std::size_t&& id)
                : id(id){
        }

        WindowId(WindowId &&other)
        noexcept: id(other.id) {
        }

        WindowId(const WindowId& other) {
            this->id = other.id;
        }

        WindowId& operator++() {
            ++this->id;
            return *this;
        }

        WindowId& operator--() {
            --this->id;
            return *this;
        }

        virtual ~WindowId() = default;

        WindowId& operator=(WindowId&& other) noexcept {
            this->id = other.id;
            return *this;
        }

        WindowId& operator=(const WindowId& other) {
            this->id = other.id;
            return *this;
        }

        WindowId& operator=(std::size_t&& other) noexcept {
            this->id = other;
            return *this;
        }

        WindowId& operator=(const std::size_t& other) {
            this->id = other;
            return *this;
        }

        [[nodiscard]] std::size_t getWindowId() const {
            return this->id;
        }

    private:
        std::size_t id;
    };
} // Apalinea::Core::Type

#endif //APALINEA_CORE_TYPE_WINDOWID_HPP
