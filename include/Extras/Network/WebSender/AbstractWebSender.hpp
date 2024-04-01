//
// Created by SlepiK on 13.02.24.
//

#ifndef ENERGYLEAF_STREAM_V1_EXPTRAS_NETWORK_ESP_ABSTRACTWEBSENDER_HPP
#define ENERGYLEAF_STREAM_V1_EXPTRAS_NETWORK_ESP_ABSTRACTWEBSENDER_HPP

namespace Energyleaf::Stream::V1::Extras::Network {
    template<typename Sender>
    class AbstractWebSender {
    public:
        AbstractWebSender() : vSender() {
        }

        AbstractWebSender(const Sender *sender)
                : vSender(sender) {
        }

        ~AbstractWebSender() = default;

        virtual void setSecure(bool secure) = 0;

        const Sender *getSenderR() {
            return this->vSender;
        }
    private:
        Sender *vSender;
    protected:
        Sender *getSender() {
            return this->vSender;
        }
    };
}

#endif
