//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT_HPP

#include <string_view>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt {
    public:
        static constexpr std::string_view Identifier{"DtInt"};
        [[nodiscard]] virtual int toInt() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT_HPP
