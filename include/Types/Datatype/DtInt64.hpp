//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT64_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT64_HPP

#include <cstdint>
#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt64 : public IDt {
    public:
        static constexpr std::string_view IDENTIFIER{"DtInt64"};

        explicit DtInt64() : IDt({IDENTIFIER}) {
        }

        explicit DtInt64(int64_t data) : IDt({IDENTIFIER}), data(data) {
        }

        DtInt64& operator=(const DtInt64 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtInt64>(*this);
        }

        [[nodiscard]] virtual int64_t toInt64() const {
            return this->data;
        }
    protected:
        int64_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT64_HPP
