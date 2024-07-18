#ifndef APALINEA_CORE_HEARTBEAT_IHEARTBEAT_HPP
#define APALINEA_CORE_HEARTBEAT_IHEARTBEAT_HPP

#include <chrono>
#include <optional>

namespace Apalinea::Core::Heartbeat {
     class IHeartbeat {
     public:
         [[maybe_unused]] [[nodiscard]] virtual std::optional<std::chrono::steady_clock::time_point> getHeartbeatTimePoint() = 0;
         [[maybe_unused]] virtual void updateHeartbeatTimePoint() = 0;
         [[maybe_unused]] virtual void sendHeartbeat() = 0;
         [[maybe_unused]] virtual bool verifyHeartbeat() = 0;
         [[maybe_unused]] virtual void handleHeartbeat() = 0;
     };
} // Apalinea::Core::Heartbeat

#endif //APALINEA_CORE_HEARTBEAT_IHEARTBEAT_HPP
