//
// Created by simon on 27.01.2024.
//

#ifndef STREAM_V1_TUPLE_TUPLEDATA_HPP
#define STREAM_V1_TUPLE_TUPLEDATA_HPP

#include <string>
#include <string_view>
#include <utility>

namespace Stream::V1::Tuple {

    template<typename ItemData>
    class Item {
    public:

        Item(std::string &&name, ItemData &&data)
                : vName(std::move(name)), vData(std::forward<ItemData>(data)) {
        }

        Item(Item &&other)
        noexcept: vName(std::move(other.vName)), vData(std::move(other.vData)) {
        }

        Item(Item &&other, ItemData &&data)
                : vName(std::move(other.vName)), vData(std::forward<ItemData>(data)) {
        }

        Item(const Item& other) {
            vData = other.vData;
            vName = other.vName;
        }

        virtual ~Item() = default;

        Item& operator=(Item&& other) noexcept {
            vData = std::move(other.vData);
            vName = std::move(other.vName);
            return *this;
        }

        Item& operator=(const Item& other) {
            vData = other.vData;
            vName = other.vName;
            return *this;
        }

        ItemData getData() const {
            return this->vData;
        }

        [[nodiscard]] std::string_view getName() const {
            return this->vName;
        }

        void updateName(std::string&& name) {
            this->vName = std::move(name);
        }

    private:
        ItemData vData;
        std::string vName;
    };

} // Stream::V1::Tuple

#endif //STREAM_V1_TUPLE_TUPLEDATA_HPP
