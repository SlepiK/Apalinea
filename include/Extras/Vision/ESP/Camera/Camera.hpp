//
// Created by SlepiK on 01.02.24.
//

#ifndef ENERGYLEAF_STREAM_V1_EXPTRAS_NETWORK_ESP_CAMERA_HPP
#define ENERGYLEAF_STREAM_V1_EXPTRAS_NETWORK_ESP_CAMERA_HPP

#ifdef ENERGYLEAF_ESP
#endif

namespace Energyleaf::Stream::V1::Extras::Vision::ESP {
    class Camera {
    public:
        Camera() = default;

        virtual ~Camera() {
            this->stop();
        };

        void start() {

        }

        void stop() {

        };
    private:
    protected:
    };
}

#endif //ENERGYLEAF_STREAM_V1_EXPTRAS_NETWORK_ESP_CAMERA_HPP
