//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_ILINK_HPP
#define STREAM_V1_LINK_ILINK_HPP

namespace Energyleaf::Stream::V1::Link {
    class ILink {
    public:
        virtual ~ILink() = default;

        virtual void process() = 0;

        [[nodiscard]] virtual bool isProcessing() const = 0;

        [[nodiscard]] virtual bool isProcessed() const = 0;
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_ILINK_HPP
