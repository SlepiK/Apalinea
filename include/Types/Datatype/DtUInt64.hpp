//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTUINT64_HPP
#define STREAM_V1_TYPES_DATATYPE_DTUINT64_HPP

#include <cstdint>
#include <string_view>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtUInt64 {
    public:
        static constexpr std::string_view Identifier{"DtUInt64"};
        [[nodiscard]] virtual uint64_t toUInt64() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTUINT64_HPP
