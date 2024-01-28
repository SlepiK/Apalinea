//
// Created by SlepiK on 27.01.2024.
//

#include "../../include/Tuple/Tuple.hpp"

namespace Stream::V1::Tuple {
    template<typename... ItemData>
    void Tuple<ItemData...>::addItem(const Tuple<ItemData...> &other) {
        this->vItems.insert(this->vItems.end(), other.vItems.begin(), other.vItems.end());
    }

    template<typename... ItemData>
    void Tuple<ItemData...>::addItem(Tuple<ItemData...> &&other) {
        this->vItems.insert(this->vItems.end(), std::make_move_iterator(other.vItems.begin()),
                            std::make_move_iterator(other.vItems.end()));
        other.vItems.clear();
    }


    template<typename... ItemData>
    template<typename ItemDataT, typename>
    void Tuple<ItemData...>::addItem(const std::string &name, const ItemDataT &itemData) {
        this->vItems.push_back(Item<ItemDataT>(name,itemData));
    }

    template<typename... ItemData>
    template<typename ItemDataT, typename>
    void Tuple<ItemData...>::addItem(std::string &&name, ItemDataT &&itemData) {
        this->vItems.push_back(Item<ItemDataT>(std::move(name),std::forward<ItemDataT>(itemData)));
    }


    template<typename... ItemData>
    template<typename ItemDataT, typename>
    void Tuple<ItemData...>::addItem(const Item<ItemDataT> &item) {
        this->vItems.push_back(item);
    }

    template<typename... ItemData>
    template<typename ItemDataT, typename>
    void Tuple<ItemData...>::addItem(Item<ItemDataT> &&item) {
        this->vItems.push_back(std::move(item));
    }


    template<typename... ItemData>
    void Tuple<ItemData...>::addItem(const std::variant<Item<ItemData>...> &item) {
        this->vItems.push_back(item);
    }

    template<typename... ItemData>
    void Tuple<ItemData...>::addItem(std::variant<Item<ItemData>...> &&item) {
        this->vItems.push_back(std::move(item));
    }


    template<typename... ItemData>
    template<typename ItemDataT, typename>
    void Tuple<ItemData...>::updateItem(const std::string &name, const ItemDataT &itemData, const std::size_t index) {
        this->vItems.at(index) = Item<ItemDataT>(name,itemData);
    }

    template<typename... ItemData>
    template<typename ItemDataT, typename>
    void Tuple<ItemData...>::updateItem(std::string &&name, ItemDataT &&itemData, const std::size_t index) {
        this->vItems.at(index) = Item<ItemDataT>(std::move(name),std::forward<ItemDataT>(itemData));
    }


    template<typename... ItemData>
    template<typename ItemDataT, typename>
    void Tuple<ItemData...>::updateItem(const Item<ItemDataT> &item, const std::size_t index) {
        this->vItems.at(index) = item;
    }

    template<typename... ItemData>
    template<typename ItemDataT, typename>
    void Tuple<ItemData...>::updateItem(Item<ItemDataT> &&item, const std::size_t index) {
        this->vItems.at(index) = std::move(item);
    }


    template<typename... ItemData>
    void Tuple<ItemData...>::updateItem(const std::variant<Item<ItemData>...> &item, const std::size_t index) {
        this->vItems.at(index) = item;
    }

    template<typename... ItemData>
    void Tuple<ItemData...>::updateItem(std::variant<Item<ItemData>...> &&item, const std::size_t index) {
        this->vItems.at(index) = std::move(item);
    }


    template<typename... ItemData>
    void Tuple<ItemData...>::UpdateItemName(const std::string &name, const std::size_t index) {
        std::variant<Item<ItemData>...>& item = this->vItems.at(index);

        std::visit([&name](Item<ItemData>& tmpItem) {
            tmpItem.setName(name);
        }..., item);
    }

    template<typename... ItemData>
    void Tuple<ItemData...>::UpdateItemName(std::string &&name, const std::size_t index) {
        std::variant<Item<ItemData>...>& item = this->vItems.at(index);

        std::visit([&name](Item<ItemData>& tmpItem) {
            tmpItem.setName(name);
        }..., item);
    }


    template<typename... ItemData>
    const std::variant<Item<ItemData>...> &Tuple<ItemData...>::getItem(const std::size_t index) const {
        return this->vItems.at(index);
    }

    template<typename... ItemData>
    std::variant<Item<ItemData>...> Tuple<ItemData...>::getItemC(const std::size_t index) const {
        return this->vItems.at(index);
    }


    template<typename... ItemData>
    template<typename ItemDataT, typename>
    const Item<ItemDataT> &Tuple<ItemData...>::getItem(const std::size_t index) const {
        return std::get<Item<ItemDataT>>(this->vItems.at(index));
    }

    template<typename... ItemData>
    template<typename ItemDataT, typename>
    Item<ItemDataT> Tuple<ItemData...>::getItemC(const std::size_t index) {
        return std::get<Item<ItemDataT>>(this->vItems.at(index));
    }
} // Stream