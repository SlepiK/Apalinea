//
// Created by SlepiK on 21.02.2024.
//

#ifndef STREAM_V1_TUPLE_ITEM_ITEMTYPEREGISTRY_HPP
#define STREAM_V1_TUPLE_ITEM_ITEMTYPEREGISTRY_HPP

#include <unordered_map>
#include "ItemType.hpp"

namespace Energyleaf::Stream::V1::Tuple {
    class ItemTypeRegistry {
    public:
        template<typename ...ItemTypeArgs>
        explicit ItemTypeRegistry(const ItemTypeArgs&... types) : vRegistered(types...){
        }

        void addItemType(const ItemType& type) {

        }

        void removeItemType(const ItemType& type) {

        }

        void removeItemType(std::size_t index) {

        }

        bool containsItemType(const ItemType& type) {
            return false;
        }

        int getIndexOfType(const ItemType& type) {

        }
    private:
        std::unordered_map<int,ItemType> vRegistered;
    protected:
    };
}

#endif //STREAM_V1_TUPLE_ITEM_ITEMTYPEREGISTRY_HPP
