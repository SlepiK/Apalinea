//
// Created by SlepiK on 30.01.24.
//

#ifndef ENERGYLEAF_STREAM_V1_EXPTRAS_NETWORK_ESP_WEBSENDER_HPP
#define ENERGYLEAF_STREAM_V1_EXPTRAS_NETWORK_ESP_WEBSENDER_HPP

#include <cstdint>
#include <string>

#ifdef ENERGYLEAF_ESP
#include <WiFiClientSecure.h>
#endif

#ifdef ENERGYLEAF_ESP
extern const std::uint8_t rootca_crt_bundle_start[] asm(
"_binary_data_cert_x509_crt_bundle_bin_start");
#endif

namespace Energyleaf::Stream::V1::Extras::Network::ESP {
    /**
     * Class is designed only for usage on an ESP!
     */
    template<typename T>
    class WebSender {
    public:
        explicit WebSender() :
#ifdef ENERGYLEAF_ESP
        vWifiClientSecure(),
#endif
        vPortSet(false),
        vCertSet(false),
        vPort(-1){
#ifdef ENERGYLEAF_ESP
            vWifiClientSecure.setCACertBundle(rootca_crt_bundle_start);
            if (rootca_crt_bundle_start != nullptr) {
                vCertSet = true;
            }
#endif
        }

#ifdef ENERGYLEAF_ESP
        explicit WebSender(WiFiClientSecure& client,bool loadCert = true)
            : vWifiClientSecure(client) {
                if (loadCert) {
                    vWifiClientSecure.setCACertBundle(rootca_crt_bundle_start);
                }
        }
#endif

#ifdef ENERGYLEAF_ESP
        explicit WebSender(WebSender& other) : Sender(other.vWifiClientSecure,!other.vCertSet) {
        }
#endif

        virtual ~WebSender() = default;

        void setHost(const std::string& host) { this->vHost = host; }

        void setPort(int port) {
            this->vPort = port;
            this->vPortSet = true;
        }

    private:
    protected:
        std::string vHost;
        int vPort;
        bool vPortSet;
        bool vCertSet;
        virtual void send(const T& data) = 0;
#ifdef ENERGYLEAF_ESP
        WiFiClientSecure vWifiClientSecure;
#endif
    };
}

#endif //ENERGYLEAF_STREAM_V1_EXPTRAS_NETWORK_ESP_WEBSENDER_HPP
