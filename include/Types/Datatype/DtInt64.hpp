//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT64_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT64_HPP

#include <cstdint>
#include <string_view>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt64 {
    public:
        static constexpr std::string_view Identifier{"DtInt64"};
        [[nodiscard]] virtual int64_t toInt64() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT64_HPP
