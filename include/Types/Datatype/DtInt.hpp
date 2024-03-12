//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT_HPP

#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt : public IDt {
    public:
        static constexpr std::string_view IDENTIFIER{"DtInt"};

        DtInt() : IDt({IDENTIFIER}) {
        }

        explicit DtInt(int &&data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtInt>(*this);
        }

        [[nodiscard]] virtual int toInt() const {
            return this->data;
        }
    protected:
        int data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT_HPP
