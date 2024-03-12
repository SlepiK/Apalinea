//
// Created by SlepiK on 10.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT8_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT8_HPP

#include <cstdint>
#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt8 : public IDt {
    public:
        static constexpr std::string_view IDENTIFIER{"DtInt8"};

        explicit DtInt8() : IDt({IDENTIFIER}) {
        }

        explicit DtInt8(int8_t data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtInt8>(*this);
        }

        [[nodiscard]] virtual int8_t toInt8() const {
            return this->data;
        }
    protected:
        int8_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT8_HPP
