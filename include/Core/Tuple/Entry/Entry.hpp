#ifndef APALINEA_CORE_TUPLE_ENTRY_HPP
#define APALINEA_CORE_TUPLE_ENTRY_HPP

#include <memory>
#include "Core/Type/Datatype/IDt.hpp"
#include "Core/Tuple/Trait/TupleTrait.hpp"

namespace Apalinea::Core::Tuple {
    class Entry {
    public:
        Entry() = default;

        template <typename T>
        Entry(T item) : vItem(std::make_unique<T>(std::move(item))) {
        }

        Entry(const Entry& entry) : vItem(entry.vItem->copy()) {
        }

        Entry(Entry&&) noexcept = default;

        Entry& operator=(const Entry& entry) {
            return *this = Entry(entry);
        }

        Entry& operator=(Entry&&) noexcept = default;

        template<typename T>
        const T& get() const {
            static_assert(HasTypeAnIdentifier<T>::value, "Wanted Type did not have a static identifier specifier!");
            if(vItem->isBasedOn(T::IDENTIFIER)) {
                return static_cast<const T&>(*vItem);
            } else {
                throw std::runtime_error("Could not cast to Type!");
            }
        }

    private:
        std::unique_ptr<Type::Datatype::IDt> vItem;
    };
} // Apalinea::Core::Tuple

#endif //APALINEA_CORE_TUPLE_ENTRY_HPP
