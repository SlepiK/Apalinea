//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTUINT32_HPP
#define STREAM_V1_TYPES_DATATYPE_DTUINT32_HPP

#include <cstdint>
#include <string_view>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtUInt32 {
    public:
        static constexpr std::string_view Identifier{"DtUInt32"};
        [[nodiscard]] virtual uint32_t toUInt32() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTUINT32_HPP
