//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_TUPLE_TUPLE_HPP
#define STREAM_V1_TUPLE_TUPLE_HPP

#include <vector>
#include <variant>

#include "Item/Item.hpp"

namespace Energyleaf::Stream::V1::Tuple {

    template<typename... ItemData>
    class Tuple {
    public:
        Tuple() = default;

        Tuple(Tuple<ItemData...> &&other)
        noexcept: vItems(std::move(other.vItems)) {
        }

        Tuple(const Tuple<ItemData...>& other) {
            vItems = other.vItems;
        }

        virtual ~Tuple() = default;

        Tuple& operator=(Tuple<ItemData...>&& other) noexcept {
            vItems = std::move(other.vItems);
            return *this;
        }

        Tuple& operator=(const Tuple<ItemData...>& other) {
            vItems = other.vItems;
            return *this;
        }

        void addItem(const Tuple<ItemData...> &other) {
            this->vItems.insert(this->vItems.end(), other.vItems.begin(), other.vItems.end());
        }

        void addItem(Tuple<ItemData...> &&other) {
            this->vItems.insert(this->vItems.end(), std::make_move_iterator(other.vItems.begin()),
                                std::make_move_iterator(other.vItems.end()));
            other.vItems.clear();
        }

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void addItem(const std::string &name, ItemDataT &&itemData) {
            this->vItems.push_back(Item<ItemDataT>(name, std::forward<ItemDataT>(itemData)));
        }

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void addItem(const std::string &name, const ItemDataT &itemData) {
            this->vItems.push_back(Item<ItemDataT>(name,itemData));
        }

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void addItem(std::string &&name, ItemDataT &&itemData) {
            this->vItems.push_back(Item<ItemDataT>(std::move(name),std::forward<ItemDataT>(itemData)));
        }

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void addItem(std::string &&name, ItemDataT &itemData) {
            this->vItems.push_back(Item<ItemDataT>(std::move(name),std::forward<ItemDataT>(itemData)));
        }

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void addItem(const Item<ItemDataT> &item) {
            this->vItems.push_back(item);
        }

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void addItem(Item<ItemDataT> &&item) {
            this->vItems.push_back(std::move(item));
        }


        void addItem(const std::variant<Item<ItemData>...> &item) {
            this->vItems.push_back(item);
        }

        void addItem(std::variant<Item<ItemData>...> &&item) {
            this->vItems.push_back(std::move(item));
        }


        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void updateItem(const std::string &name, const ItemDataT &itemData, std::size_t index) {
            this->vItems.at(index) = Item<ItemDataT>(name,itemData);
        }

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void updateItem(std::string &&name, ItemDataT &&itemData, std::size_t index) {
            this->vItems.at(index) = Item<ItemDataT>(std::move(name),std::forward<ItemDataT>(itemData));
        }


        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void updateItem(const Item<ItemDataT> &item, std::size_t index) {
            this->vItems.at(index) = item;
        }

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        void updateItem(Item<ItemDataT> &&item, std::size_t index) {
            this->vItems.at(index) = std::move(item);
        }


        void updateItem(const std::variant<Item<ItemData>...> &item, std::size_t index) {
            this->vItems.at(index) = item;
        }

        void updateItem(std::variant<Item<ItemData>...> &&item, std::size_t index) {
            this->vItems.at(index) = std::move(item);
        }


        void UpdateItemName(const std::string &name, std::size_t index) {
            std::variant<Item<ItemData>...>& item = this->vItems.at(index);

            std::visit([&name](Item<ItemData>& tmpItem) {
                tmpItem.setName(name);
            }..., item);
        }

        void UpdateItemName(std::string &&name, std::size_t index) {
            std::variant<Item<ItemData>...>& item = this->vItems.at(index);

            std::visit([&name](Item<ItemData>& tmpItem) {
                tmpItem.setName(name);
            }..., item);
        }


        const std::variant<Item<ItemData>...> &getItem(std::size_t index) const {
            return this->vItems.at(index);
        }

        std::variant<Item<ItemData>...> getItemC(std::size_t index) const {
            return this->vItems.at(index);
        }


        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        const Item<ItemDataT> &getItem(std::size_t index) const {
            return std::get<Item<ItemDataT>>(this->vItems.at(index));
        }

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT, ItemData>...>>>
        Item<ItemDataT> getItemC(std::size_t index) {
            return std::get<Item<ItemDataT>>(this->vItems.at(index));
        }


        const std::vector<std::variant<Item<ItemData>...>> &getItemVector() const {
            return this->vItems;
        }

        void clear() {
            this->vItems.clear();
        }

    private:
        std::vector<std::variant<Item<ItemData>...>> vItems;
    };

} // Stream

#endif //STREAM_V1_TUPLE_TUPLE_HPP
