//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_ILINK_HPP
#define STREAM_V1_LINK_ILINK_HPP

#include <vector>
#include <optional>
#include "Wrapper/LinkWrapper.hpp"
#include "IBaseLink.hpp"

namespace Energyleaf::Stream::V1::Link {
    class ILink : virtual public IBaseLink {
    public:
        virtual ~ILink() = default;

        virtual void process() = 0;

        [[nodiscard]] virtual bool isProcessing() const = 0;

        [[nodiscard]] virtual bool isProcessed() const = 0;

        virtual std::optional<std::reference_wrapper<const std::vector<std::shared_ptr<LinkWrapper>>>> getLinks() = 0;
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_ILINK_HPP
