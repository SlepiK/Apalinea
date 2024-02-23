//
// Created by SlepiK on 17.02.2024.
//

#ifndef STREAM_V1_TYPES_TBASEITEM_HPP
#define STREAM_V1_TYPES_TBASEITEM_HPP

#include <Tuple/Item/Item.hpp>
#include <memory>
#include <sstream>

namespace Energyleaf::Stream::V1::Types::Base {
    template<typename T>
    class TBaseItem : public Energyleaf::Stream::V1::Tuple::Item {
    public:
        TBaseItem(T&& data) : vData(std::move(data)) {
        }

        [[nodiscard]] const T& getData() const {
            return vData;
        }
    private:
    protected:
        T vData;
    };

    template<>
    class TBaseItem<std::string> : public Energyleaf::Stream::V1::Tuple::Item {
    public:
        TBaseItem(std::string&& data) : vData(std::move(data)) {
        }

        [[nodiscard]] const std::string& getData() const {
            return vData;
        }
    private:
    protected:
        std::string vData;
    };
}

#endif //STREAM_V1_TYPES_TBASEITEM_HPP
