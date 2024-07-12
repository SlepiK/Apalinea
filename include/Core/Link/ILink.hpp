#ifndef APALINEA_CORE_LINK_ILINK_HPP
#define APALINEA_CORE_LINK_ILINK_HPP

#include <vector>
#include <optional>
#include "Core/Link/IBaseLink.hpp"
#include "Core/Link/Wrapper/LinkWrapper.hpp"

namespace Apalinea::Core::Link {
    class ILink : virtual public IBaseLink {
    public:
        ~ILink() override = default;

        virtual void process() = 0;

        [[maybe_unused]] [[nodiscard]] virtual bool isProcessing() const = 0;

        [[nodiscard]] virtual bool isProcessed() const = 0;

        virtual std::optional<std::reference_wrapper<const std::vector<std::shared_ptr<LinkWrapper>>>> getLinks() = 0;

        [[maybe_unused]] [[nodiscard]] virtual bool isTimeBasedExecutionNeeded() const = 0;
    };
} // Apalinea::Core::Link

#endif //APALINEA_CORE_LINK_ILINK_HPP
