//
// Created by SlepiK on 10.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTSTRING_HPP
#define STREAM_V1_TYPES_DATATYPE_DTSTRING_HPP

#include <string>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtString {
    public:
        static constexpr std::string_view Identifier{"DtString"};
        [[nodiscard]] virtual std::string_view toString() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTSTRING_HPP
