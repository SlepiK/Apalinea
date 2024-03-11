//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTSIZET_HPP
#define STREAM_V1_TYPES_DATATYPE_DTSIZET_HPP

#include <cstddef>
#include <string_view>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtSizeT {
    public:
        static constexpr std::string_view Identifier{"DtSizeT"};
        [[nodiscard]] virtual std::size_t toSizeT() const = 0;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTSIZET_HPP
