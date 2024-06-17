//
// Created by SlepiK on 17.06.24.
//

#ifndef STREAM_V1_LINK_LINKTYPE_HPP
#define STREAM_V1_LINK_LINKTYPE_HPP

namespace Energyleaf::Stream::V1::Link {
    enum class LinkType : int {
        SOURCE = 0,
        PIPE = 1,
        SINK = 2
    };
}

#endif //STREAM_V1_LINK_LINKTYPE_HPP
