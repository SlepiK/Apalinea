#ifndef APALINEA_CORE_HEARTBEAT_HEARTBEATSTATE_HPP
#define APALINEA_CORE_HEARTBEAT_HEARTBEATSTATE_HPP

namespace Apalinea::Core::Heartbeat {
    enum class HeartbeatState : int {
        NO_HEARTBEAT = 0,
        HEARTBEAT = 1
    };
}

#endif //APALINEA_CORE_HEARTBEAT_HEARTBEATSTATE_HPP
