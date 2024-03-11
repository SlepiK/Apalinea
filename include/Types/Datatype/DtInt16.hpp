//
// Created by SlepiK on 10.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT16_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT16_HPP

#include <cstdint>
#include <string_view>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt16 {
    public:
        static constexpr std::string_view Identifier{"DtInt16"};
        [[nodiscard]] virtual int16_t toInt16() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT16_HPP
