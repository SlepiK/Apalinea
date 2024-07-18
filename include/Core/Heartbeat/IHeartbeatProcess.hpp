#ifndef APALINEA_CORE_HEARTBEAT_IHEARTBEATPROCESS_HPP
#define APALINEA_CORE_HEARTBEAT_IHEARTBEATPROCESS_HPP

namespace Apalinea::Core::Heartbeat {
    class IHeartbeatProcess {
    public:
        [[maybe_unused]] virtual void handleHeartbeat() = 0;
    };
}

#endif //APALINEA_CORE_HEARTBEAT_IHEARTBEATPROCESS_HPP
