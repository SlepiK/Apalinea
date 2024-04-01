//
// Created by SlepiK on 01.04.2024.
//

#include "DtImage.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    IDt *DtImage::operator+(const IDt &other) const {
        throw Exception::NotImplementedException("Method not supported here!");
    }

    IDt *DtImage::operator-(const IDt &other) const {
        throw Exception::NotImplementedException("Method not supported here!");
    }

    IDt *DtImage::operator*(const IDt &other) const {
        throw Exception::NotImplementedException("Method not supported here!");
    }

    IDt *DtImage::operator/(const IDt &other) const {
        throw Exception::NotImplementedException("Method not supported here!");
    }

    IDt *DtImage::operator^(const IDt &other) const {
        throw Exception::NotImplementedException("Method not supported here!");
    }

    IDt *DtImage::operator%(const IDt &other) const {
        throw Exception::NotImplementedException("Method not supported here!");
    }
}