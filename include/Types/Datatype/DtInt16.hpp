//
// Created by SlepiK on 10.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT16_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT16_HPP

#include <cstdint>
#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt16 : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtInt16"};

        explicit DtInt16() : IDt({IDENTIFIER}) {
        }

        explicit DtInt16(int16_t data) : IDt({IDENTIFIER}), data(data) {
        }

        DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtInt16& operator=(const DtInt16 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtInt16>(*this);
        }

        [[nodiscard]] virtual int16_t toInt16() const {
            return this->data;
        }
    protected:
        int16_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT16_HPP
