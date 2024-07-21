#ifndef APALINEA_CORE_LINK_IBASELINK_HPP
#define APALINEA_CORE_LINK_IBASELINK_HPP

#include "Core/Link/Type/LinkType.hpp"
#include "Core/Heartbeat/AbstractHeartbeat.hpp"

namespace Apalinea::Core::Link {
    class IBaseLink : protected Apalinea::Core::Heartbeat::AbstractHeartbeat {
    public:
        virtual ~IBaseLink() = default;

        [[nodiscard]] virtual LinkType getType() const = 0;
    };
} // Apalinea::Core::Link

#endif //APALINEA_CORE_LINK_IBASELINK_HPP
