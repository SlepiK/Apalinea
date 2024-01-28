//
// Created by simon on 27.01.2024.
//

#ifndef STREAM_V1_TUPLE_TUPLEDATA_HPP
#define STREAM_V1_TUPLE_TUPLEDATA_HPP

#include <string>
#include <string_view>
#include <utility>

namespace Stream::V1::Tuple {

    template<typename TData>
    class Item {
    public:

        Item(std::string&& name, TData&& data)
            : vName(std::move(name)), vData(std::forward<TData>(data)) {
        }

        Item(Item&& other)
            : vName(std::move(other.vName)), vData(std::move(other.vData)) {
        }

        Item(Item&& other, TData&& data)
            : vName(std::move(other.vName)), vData(std::forward<Tdata>(data)) {
        }

        virtual ~Item() = default;

        TData getData() const;

        std::string_view getName() const;

        void updateName(std::string&& name);

    private:
        const TData vData;
        std::string vName;
    };

    template <>
    class Item<void> {
    public:
        Item(std::string&& name)
                : vName(std::move(name)) {
        }

        Item(Item&& other)
                : vName(std::move(other.vName)) {
        }

        virtual ~Item() = default;

        std::string_view getName() const;

        void updateName(std::string&& name);

    private:
        std::string vName;
    };

} // Stream::V1::Tuple

#endif //STREAM_V1_TUPLE_TUPLEDATA_HPP
