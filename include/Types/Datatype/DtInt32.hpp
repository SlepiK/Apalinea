//
// Created by SlepiK on 10.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT32_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT32_HPP

#include <cstdint>
#include <string_view>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt32 {
    public:
        static constexpr std::string_view Identifier{"DtInt32"};
        [[nodiscard]] virtual int32_t toInt32() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT32_HPP
