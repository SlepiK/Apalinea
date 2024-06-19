#ifndef APALINEA_EXTRAS_NETWORK_ESP_ABSTRACTWEBSENDER_HPP
#define APALINEA_EXTRAS_NETWORK_ESP_ABSTRACTWEBSENDER_HPP

namespace Apalinea::Extras::Network {
    template<typename Sender>
    class AbstractWebSender {
    public:
        AbstractWebSender() : vSender(new Sender()) {
        }

        AbstractWebSender(Sender *sender)
                : vSender(sender) {
        }

        ~AbstractWebSender() = default;

        void setSender(const AbstractWebSender &other) {
            delete this->vSender;
            this->vSender = other.vSender;
        }

        Sender *getSender() {
            return this->vSender;
        }
    private:
        Sender *vSender;
    protected:
    };
} //Apalinea::Extras::Network

#endif //APALINEA_EXTRAS_NETWORK_ESP_ABSTRACTWEBSENDER_HPP
