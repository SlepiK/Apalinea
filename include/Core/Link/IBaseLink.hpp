//
// Created by SlepiK on 17.06.24.
//

#ifndef STREAM_V1_LINK_IBASELINK_HPP
#define STREAM_V1_LINK_IBASELINK_HPP

#include "Core/Link/Type/LinkType.hpp"

namespace Apalinea::Core::Link {
    class IBaseLink {
    public:
        virtual ~IBaseLink() = default;

        [[nodiscard]] virtual LinkType getType() const = 0;
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_IBASELINK_HPP
