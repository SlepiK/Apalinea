//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTUINT16_HPP
#define STREAM_V1_TYPES_DATATYPE_DTUINT16_HPP

#include <cstdint>
#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtUInt16 : public IDt {
    public:
        static constexpr std::string_view IDENTIFIER{"DtUInt16"};

        explicit DtUInt16() : IDt({IDENTIFIER}) {
        }

        explicit DtUInt16(uint16_t data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtUInt16>(*this);
        }

        [[nodiscard]] virtual uint16_t toUInt16() const {
            return this->data;
        }
    protected:
        uint16_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTUINT16_HPP