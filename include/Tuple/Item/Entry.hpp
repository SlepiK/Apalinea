//
// Created by simon on 27.01.2024.
//

#ifndef STREAM_V1_TUPLE_TUPLEDATA_HPP
#define STREAM_V1_TUPLE_TUPLEDATA_HPP

#include <memory>
#include "Item.hpp"
#include "ItemTrait.hpp"

namespace Energyleaf::Stream::V1::Tuple {

    class Entry {
    public:
        //ToDo: Find a better name for x
        template <typename T>
        Entry(T x) : vItem(std::make_unique<T>(std::move(x))) {
        }

        Entry(const Entry& item) : vItem(item.vItem->copy()) {
        }

        Entry(Entry&&) noexcept = default;

        Entry& operator=(const Entry& item) {
            return *this = Entry(item);
        }

        Entry& operator=(Entry&&) noexcept = default;

        template<typename T>
        T& get() {
            static_assert(std::is_base_of<Item,T>::value,"Used type must be derived from Item!");
            static_assert(std::is_same<std::remove_cv_t<T>, std::remove_cv_t<decltype(*vItem)>>::value,"Wanted Type must match the type of the Item!");
            static_assert(HasItemAnName<T>::value, "Wanted Type did not have a static NAME specifier!");
            if(vItem->getName() == T::NAME) {
                return static_cast<T&>(*vItem);
            } else {
                throw std::runtime_error("Could not cast to Type!");
            }
        }

    private:
        std::unique_ptr<Item> vItem;
    };

} // Stream::V1::Tuple

#endif //STREAM_V1_TUPLE_TUPLEDATA_HPP
