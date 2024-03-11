//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_TUPLEITEM_STRINGITEM_HPP
#define STREAM_V1_TYPES_TUPLEITEM_STRINGITEM_HPP

#include <Tuple/Item/IItime.hpp>
#include <Types/Datatype/DtString.hpp>

namespace Energyleaf::Stream::V1::Types::TupleItem {
    class StringItem : public Energyleaf::Stream::V1::Tuple::IItem, public Energyleaf::Stream::V1::Types::Datatype::DtString {
    public:
        explicit StringItem(std::string &&data) : IItem({Energyleaf::Stream::V1::Types::Datatype::DtString::Identifier}), vData(std::move(data)) {
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Tuple::IItem> copy() const override {
            return std::make_unique<StringItem>(*this);
        }

        std::string_view toString() const override {
            return this->vData;
        }
    private:
        std::string vData;
    };
}

#endif //STREAM_V1_TYPES_TUPLEITEM_STRINGITEM_HPP
