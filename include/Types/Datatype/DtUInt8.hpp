//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTUINT8_HPP
#define STREAM_V1_TYPES_DATATYPE_DTUINT8_HPP

#include <cstdint>
#include <string_view>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtUInt8 {
    public:
        static constexpr std::string_view Identifier{"DtUInt8"};
        [[nodiscard]] virtual uint8_t toUInt8() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTUINT8_HPP
