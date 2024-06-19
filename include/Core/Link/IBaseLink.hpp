#ifndef APALINEA_CORE_LINK_IBASELINK_HPP
#define APALINEA_CORE_LINK_IBASELINK_HPP

#include "Core/Link/Type/LinkType.hpp"

namespace Apalinea::Core::Link {
    class IBaseLink {
    public:
        virtual ~IBaseLink() = default;

        [[nodiscard]] virtual LinkType getType() const = 0;
    };
} // Apalinea::Core::Link

#endif //APALINEA_CORE_LINK_IBASELINK_HPP
