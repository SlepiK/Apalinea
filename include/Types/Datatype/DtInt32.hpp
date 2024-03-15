//
// Created by SlepiK on 10.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT32_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT32_HPP

#include <cstdint>
#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt32 : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtInt32"};

        explicit DtInt32() : IDt({IDENTIFIER}) {
        }

        explicit DtInt32(int32_t data) : IDt({IDENTIFIER}), data(data) {
        }

        DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtInt32& operator=(const DtInt32 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtInt32>(*this);
        }

        [[nodiscard]] virtual int32_t toInt32() const {
            return this->data;
        }
    protected:
        int32_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT32_HPP
