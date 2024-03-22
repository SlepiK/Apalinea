//
// Created by SlepiK on 10.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTSTRING_HPP
#define STREAM_V1_TYPES_DATATYPE_DTSTRING_HPP

#include <string>
#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtString : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtString"};

        explicit DtString() : IDt({IDENTIFIER}) {
        }

        explicit DtString(std::string &&data) : IDt({IDENTIFIER}), data(std::move(data)) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtString& operator=(const DtString &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtString>(*this);
        }

        [[nodiscard]] virtual const std::string& toString() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toString() == (static_cast<const DtString&>(other)).toString();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toString() != (static_cast<const DtString&>(other)).toString();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            throw std::runtime_error("DtString dont support < operator!");
        }

        bool operator>(const IDt& other) const override {
            throw std::runtime_error("DtString dont support > operator!");
        }

        bool operator<=(const IDt& other) const override {
            throw std::runtime_error("DtString dont support <= operator!");
        }

        bool operator>=(const IDt& other) const override {
            throw std::runtime_error("DtString dont support >= operator!");
        }
    protected:
        std::string data;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTSTRING_HPP
