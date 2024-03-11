//
// Created by SlepiK on 10.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT8_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT8_HPP

#include <cstdint>
#include <string_view>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt8 {
    public:
        static constexpr std::string_view Identifier{"DtInt8"};
        [[nodiscard]] virtual int8_t toInt8() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT8_HPP
