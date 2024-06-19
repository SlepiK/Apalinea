//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_ILINK_HPP
#define STREAM_V1_LINK_ILINK_HPP

#include <vector>
#include <optional>
#include "Core/Link/IBaseLink.hpp"
#include "Core/Link/Wrapper/LinkWrapper.hpp"

namespace Apalinea::Core::Link {
    class ILink : virtual public IBaseLink {
    public:
        ~ILink() override = default;

        virtual void process() = 0;

        [[nodiscard]] virtual bool isProcessing() const = 0;

        [[nodiscard]] virtual bool isProcessed() const = 0;

        virtual std::optional<std::reference_wrapper<const std::vector<std::shared_ptr<LinkWrapper>>>> getLinks() = 0;
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_ILINK_HPP
