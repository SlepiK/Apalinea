//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTUINT64_HPP
#define STREAM_V1_TYPES_DATATYPE_DTUINT64_HPP

#include <cstdint>
#include <string_view>
#include <utility>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtUInt64 : public IDt {
    public:
        static constexpr std::string_view IDENTIFIER{"DtUInt64"};

        explicit DtUInt64() : IDt({IDENTIFIER}) {
        }

        explicit DtUInt64(uint64_t data) : IDt({IDENTIFIER}), data(data) {
        }

        DtUInt64& operator=(const DtUInt64 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtUInt64>(*this);
        }

        [[nodiscard]] virtual uint64_t toUInt64() const {
            return this->data;
        }
    protected:
        uint64_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTUINT64_HPP
