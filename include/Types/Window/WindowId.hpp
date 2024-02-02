//
// Created by SlepiK on 29.01.24.
//

#ifndef ENERGYLEAF_STREAM_V1_TYPES_WINDOWID_HPP
#define ENERGYLEAF_STREAM_V1_TYPES_WINDOWID_HPP

#include <utility>
#include <cstddef>

namespace Energyleaf::Stream::V1::Types {
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
}

#endif //ENERGYLEAF_STREAM_V1_TYPES_WINDOWID_HPP
