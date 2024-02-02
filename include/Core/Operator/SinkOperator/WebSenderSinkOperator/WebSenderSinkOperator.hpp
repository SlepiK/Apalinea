//
// Created by SlepiK on 30.01.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATOR_WEBSENDERSINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATOR_WEBSENDERSINKOPERATOR_HPP

#include <utility>
#include <cstddef>
#include <cstring>

#include "Operator/SinkOperator/AbstractSinkOperator.hpp"
#include "Tuple/Tuple.hpp"
#include "Types/Power/Power.hpp"
#include "Extras/Network/ESP/WebSender/WebSender.hpp"
#include "Types/Buffer/ELData.pb.h"

namespace Energyleaf::Stream::V1::Core::Operator::SinkOperator {
    class WebSenderSinkOperator : public Energyleaf::Stream::V1::Operator::AbstractSinkOperator<Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Power>>, public Energyleaf::Stream::V1::Extras::Network::ESP::WebSender<Energyleaf::Stream::V1::Types::Power> {
    public:
        void setSensorId(char sensorId[128]) {
            std::copy(sensorId, sensorId + std::strlen(sensorId), this->vSensorId);
        }

        void setSensorId(const std::string& sensorId) {
            if (sensorId.length() > 120) {
                throw std::runtime_error("SensorId to big to store!");
            }
            strcpy(this->vSensorId, sensorId.c_str());
        }

        void setEndpoint(std::string endpoint) { this->vEndpoint = std::move(endpoint); }
    private:
        char vSensorId[128];
        std::string vEndpoint;
    protected:
        void work(Energyleaf::Stream::V1::Tuple::Tuple<Energyleaf::Stream::V1::Types::Power> &inputTuple) override {
            send(inputTuple.getItem<Energyleaf::Stream::V1::Types::Power>(0).getData());
        }

        void send(const Energyleaf::Stream::V1::Types::Power& data) override {
            if (vSensorId[0] == '\0' && this->vHost.empty() && this->vEndpoint.empty() && !this->vPortSet) {
                throw std::runtime_error("Endpointdata not set!");
            }
            ELData message = ELData_init_default;
            std::copy(std::begin(this->vSensorId), std::end(this->vSensorId), message.sensorId);
            message.sensorValue = data.getPower();

#ifdef ENERGYLEAF_ESP
            pb_ostream_t stream = pb_ostream_from_buffer(vBuffer, sizeof(vBuffer));
            if (!pb_encode(&stream, ELData_fields, &message)) {
                Serial.println("Encoding failed!");
                return;
            }
            log_d("Connecting to %s:%d",vHost.c_str(),vPort);
            vWifiClientSecure.connect(vHost.c_str(), vPort);
            if (vWifiClientSecure.connected()) {

                log_d("Connected and data is now transmitting");
                vWifiClientSecure.print("POST ");
                vWifiClientSecure.print(this->vEndpoint.c_str());
                vWifiClientSecure.println(" HTTP/1.1");
                vWifiClientSecure.print("Host: ");
                vWifiClientSecure.println(vHost.c_str());
                vWifiClientSecure.println("Content-Type: application/x-protobuf");
                vWifiClientSecure.println("Content-Length: " + String(stream.bytes_written));
                vWifiClientSecure.println();

                vWifiClientSecure.write(vBuffer, stream.bytes_written);

                vWifiClientSecure.stop();
            } else {
                throw std::runtime_error("Connection failed");
            }
#endif
        }
    };
}

#endif //STREAM_V1_CORE_OPERATOR_SINKOPERATOR_WEBSENDERSINKOPERATOR_HPP
