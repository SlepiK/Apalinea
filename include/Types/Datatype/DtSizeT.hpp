//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTSIZET_HPP
#define STREAM_V1_TYPES_DATATYPE_DTSIZET_HPP

#include <cstddef>
#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtSizeT : public IDt {
    public:
        static constexpr std::string_view IDENTIFIER{"DtSizeT"};

        explicit DtSizeT() : IDt({IDENTIFIER}) {
        }

        explicit DtSizeT(std::size_t data) : IDt({IDENTIFIER}), data(data) {
        }

        DtSizeT& operator=(const DtSizeT &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtSizeT>(*this);
        }

        [[nodiscard]] virtual std::size_t toSizeT() const {
            return this->data;
        }
    protected:
        std::size_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTSIZET_HPP
