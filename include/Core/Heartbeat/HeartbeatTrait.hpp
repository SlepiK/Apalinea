#ifndef APALINEA_CORE_HEARTBEAT_HEARTBEATTRAIT_HPP
#define APALINEA_CORE_HEARTBEAT_HEARTBEATTRAIT_HPP

#include <type_traits>
#include "Core/Heartbeat/IHeartbeat.hpp"

namespace Apalinea::Core::Heartbeat {
    template<typename T>
    struct isHeartbeat {
        static constexpr bool value = std::is_base_of<Core::Heartbeat::IHeartbeat, T>::value;
    };
}

#endif //APALINEA_CORE_HEARTBEAT_HEARTBEATTRAIT_HPP
