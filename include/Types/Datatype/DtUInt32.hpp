//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTUINT32_HPP
#define STREAM_V1_TYPES_DATATYPE_DTUINT32_HPP

#include <cstdint>
#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtUInt32 : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtUInt32"};

        explicit DtUInt32() : IDt({IDENTIFIER}) {
        }

        explicit DtUInt32(uint32_t data) : IDt({IDENTIFIER}), data(data) {
        }

        DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtUInt32& operator=(const DtUInt32 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtUInt32>(*this);
        }

        [[nodiscard]] virtual uint32_t toUInt32() const {
            return this->data;
        }
    protected:
        uint32_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTUINT32_HPP
