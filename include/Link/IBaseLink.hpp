//
// Created by SlepiK on 17.06.24.
//

#ifndef STREAM_V1_LINK_IBASELINK_HPP
#define STREAM_V1_LINK_IBASELINK_HPP

#include "Type/LinkType.hpp"

namespace Energyleaf::Stream::V1::Link {
    class IBaseLink {
    public:
        virtual ~IBaseLink() = default;

        virtual LinkType getType() const = 0;
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_IBASELINK_HPP
