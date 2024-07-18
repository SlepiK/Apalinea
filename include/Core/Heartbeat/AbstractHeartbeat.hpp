#ifndef APALINEA_CORE_HEARTBEAT_ABSTRACTHEARTBEAT_HPP
#define APALINEA_CORE_HEARTBEAT_ABSTRACTHEARTBEAT_HPP

#include "Core/Heartbeat/IHeartbeat.hpp"
#include "Core/Heartbeat/IHeartbeatProcess.hpp"
#include "Core/Heartbeat/HeartbeatState.hpp"
#include "Extras/Time/Time.hpp"

namespace Apalinea::Core::Heartbeat {
    class AbstractHeartbeat : public IHeartbeat, public IHeartbeatProcess {
    public:
        [[maybe_unused]] [[nodiscard]] std::optional<std::chrono::steady_clock::time_point> getHeartbeatTimePoint() override {
            return this->vHeartbeatTimePoint;
        }

        [[maybe_unused]] void updateHeartbeatTimePoint() override {
            this->vHeartbeatTimePoint = Apalinea::Extras::Time::Time::getCurrentTimePoint();
        }

        [[maybe_unused]] bool verifyHeartbeat() override {
            return true;
        }

    protected:
        std::chrono::steady_clock::time_point vHeartbeatTimePoint;
        Apalinea::Core::Heartbeat::HeartbeatState vHeartbeatState = Apalinea::Core::Heartbeat::HeartbeatState::NO_HEARTBEAT;
    };
}

#endif //APALINEA_CORE_HEARTBEAT_ABSTRACTHEARTBEAT_HPP
