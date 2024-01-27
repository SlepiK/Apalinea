//
// Created by SlepiK on 27.01.2024.
//

#ifndef STREAM_V1_TUPLE_TUPLE_HPP
#define STREAM_V1_TUPLE_TUPLE_HPP

#include <vector>
#include <variant>

#include "Item/Item.hpp"

namespace Stream::V1::Tuple {

    template<typename... ItemData>
    class Tuple {
    public:
        Tuple() {
        }

        Tuple(Tuple<ItemData...>&& other)
            : vItems(std::move(other.vItems)){
        }

        virtual ~Tuple() = default;

        void addItem(const Tuple<ItemData...>& other);
        void addItem(Tuple<ItemData...>&& other);

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        void addItem(const std::string& name, const ItemDataT& itemData);
        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        void addItem(std::string&& name, ItemDataT&& itemData);

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        void addItem(const Item<ItemDataT>& item);
        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        void addItem(Item<ItemDataT>&& item);

        void addItem(const std::variant<Item<ItemData>...>& item);
        void addItem(std::variant<Item<ItemData>...>&& item);

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        void updateItem(const std::string& name, const ItemDataT& itemData, const std::size_t index);
        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        void updateItem(std::string&& name, ItemDataT&& itemData, const std::size_t index);

        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        void updateItem(const Item<ItemDataT>& item, const std::size_t index);
        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        void updateItem(Item<ItemDataT>&& item, const std::size_t index);

        void updateItem(const std::variant<Item<ItemData>...>& item, const std::size_t index);
        void updateItem(std::variant<Item<ItemData>...>&& item, const std::size_t index);

        void UpdateItemName(const std::string& name, const std::size_t index);
        void UpdateItemName(std::string&& name, const std::size_t index);

        const std::vector<std::variant<Item<ItemData>...>>& getItemVector() const {
            return this->vItems;
        }

        const std::variant<Item<ItemData>...>& getItem(const std::size_t index) const;
        std::variant<Item<ItemData>...> getItemC(const std::size_t index) const;
        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        const Item<ItemDataT>& getItem(const std::size_t index) const;
        template<typename ItemDataT, typename = std::enable_if_t<std::disjunction_v<std::is_same<ItemDataT,ItemData>...>>>
        Item<ItemDataT> getItemC(const std::size_t index);

    private:
        std::vector<std::variant<Item<ItemData>...>> vItems;
    };

} // Stream

#endif //STREAM_V1_TUPLE_TUPLE_HPP
