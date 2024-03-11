//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TUPLE_IITIME_HPP
#define STREAM_V1_TUPLE_IITIME_HPP

#include <memory>
#include <unordered_set>

namespace Energyleaf::Stream::V1::Tuple {
    class IItem {
    public:
        IItem(std::initializer_list<std::string_view> datatypes) : datatypes(datatypes) {
        }
        virtual ~IItem() = default;
        [[nodiscard]] virtual std::unique_ptr<IItem> copy() const = 0;
        bool isCastAble(std::string_view datatype) const {
            return this->datatypes.find(datatype) != this->datatypes.end();
        }
    private:
        const std::unordered_set<std::string_view> datatypes;
    protected:

    };
}

#endif //STREAM_V1_TUPLE_IITIME_HPP
