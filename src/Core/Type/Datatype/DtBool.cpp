//
// Created by SlepiK on 24.03.24.
//

#include "Core/Type/Datatype/DtBool.hpp"

namespace Apalinea::Core::Types::Datatype {
    IDt *DtBool::operator+(const IDt &other) const {
        bool tmpData = this->toBool();

        if (other.getIdentifier() == this->getIdentifier()) {//Bool
            return new DtBool(tmpData + (static_cast<const DtBool &>(other)).toBool());
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtBool(tmpData + (static_cast<const DtUInt64 &>(other)).toUInt64());
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtBool(tmpData + (static_cast<const DtUInt32 &>(other)).toUInt32());
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtBool(tmpData + (static_cast<const DtUInt16 &>(other)).toUInt16());
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtBool(tmpData + (static_cast<const DtUInt8 &>(other)).toUInt8());
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtBool(tmpData + (static_cast<const DtInt64 &>(other)).toInt64());
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtBool(tmpData + (static_cast<const DtInt32 &>(other)).toInt32());
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtBool(tmpData + (static_cast<const DtInt16 &>(other)).toInt16());
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtBool(tmpData + (static_cast<const DtInt8 &>(other)).toInt8());
        } else if(other.getIdentifier() == DtInt::IDENTIFIER) {//Int
            return new DtBool(tmpData + (static_cast<const DtInt &>(other)).toInt());
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtBool(static_cast<bool>(static_cast<float>(tmpData) + (static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtBool(static_cast<bool>(static_cast<double>(tmpData) + (static_cast<const DtDouble &>(other)).toDouble()));
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtBool::operator-(const IDt &other) const {
        bool tmpData = this->toBool();

        if (other.getIdentifier() == this->getIdentifier()) {//Bool
            return new DtBool(tmpData - (static_cast<const DtBool &>(other)).toBool());
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtBool(tmpData - (static_cast<const DtUInt64 &>(other)).toUInt64());
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtBool(tmpData - (static_cast<const DtUInt32 &>(other)).toUInt32());
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtBool(tmpData - (static_cast<const DtUInt16 &>(other)).toUInt16());
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtBool(tmpData - (static_cast<const DtUInt8 &>(other)).toUInt8());
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtBool(tmpData - (static_cast<const DtInt64 &>(other)).toInt64());
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtBool(tmpData - (static_cast<const DtInt32 &>(other)).toInt32());
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtBool(tmpData - (static_cast<const DtInt16 &>(other)).toInt16());
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtBool(tmpData - (static_cast<const DtInt8 &>(other)).toInt8());
        } else if(other.getIdentifier() == DtInt::IDENTIFIER) {//Int
            return new DtBool(tmpData - (static_cast<const DtInt &>(other)).toInt());
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtBool(static_cast<bool>(static_cast<float>(tmpData) - (static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtBool(static_cast<bool>(static_cast<double>(tmpData) - (static_cast<const DtDouble &>(other)).toDouble()));
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtBool::operator*(const IDt &other) const {
        bool tmpData = this->toBool();

        if (other.getIdentifier() == this->getIdentifier()) {//Bool
            return new DtBool(tmpData * (static_cast<const DtBool &>(other)).toBool());
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtBool(tmpData * (static_cast<const DtUInt64 &>(other)).toUInt64());
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtBool(tmpData * (static_cast<const DtUInt32 &>(other)).toUInt32());
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtBool(tmpData * (static_cast<const DtUInt16 &>(other)).toUInt16());
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtBool(tmpData * (static_cast<const DtUInt8 &>(other)).toUInt8());
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtBool(tmpData * (static_cast<const DtInt64 &>(other)).toInt64());
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtBool(tmpData * (static_cast<const DtInt32 &>(other)).toInt32());
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtBool(tmpData * (static_cast<const DtInt16 &>(other)).toInt16());
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtBool(tmpData * (static_cast<const DtInt8 &>(other)).toInt8());
        } else if(other.getIdentifier() == DtInt::IDENTIFIER) {//Int
            return new DtBool(tmpData * (static_cast<const DtInt &>(other)).toInt());
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtBool(static_cast<bool>(static_cast<float>(tmpData) * (static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtBool(static_cast<bool>(static_cast<double>(tmpData) * (static_cast<const DtDouble &>(other)).toDouble()));
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtBool::operator/(const IDt &other) const {
        throw Exception::NotImplementedException("Method not supported here!");
    }

    IDt *DtBool::operator^(const IDt &other) const {
        bool tmpData = this->toBool();

        if (other.getIdentifier() == this->getIdentifier()) {//Bool
            return new DtBool(std::pow(tmpData,(static_cast<const DtBool &>(other)).toBool()));
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtBool(std::pow(tmpData,(static_cast<const DtUInt64 &>(other)).toUInt64()));
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtBool(std::pow(tmpData,(static_cast<const DtUInt32 &>(other)).toUInt32()));
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtBool(std::pow(tmpData,(static_cast<const DtUInt16 &>(other)).toUInt16()));
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtBool(std::pow(tmpData,(static_cast<const DtUInt8 &>(other)).toUInt8()));
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtBool(std::pow(tmpData,(static_cast<const DtInt64 &>(other)).toInt64()));
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtBool(std::pow(tmpData,(static_cast<const DtInt32 &>(other)).toInt32()));
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtBool(std::pow(tmpData,(static_cast<const DtInt16 &>(other)).toInt16()));
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtBool(std::pow(tmpData,(static_cast<const DtInt8 &>(other)).toInt8()));
        } else if(other.getIdentifier() == DtInt::IDENTIFIER) {//Int
            return new DtBool(std::pow(tmpData,(static_cast<const DtInt &>(other)).toInt()));
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtBool(static_cast<bool>(std::pow(tmpData,(static_cast<const DtFloat &>(other)).toFloat())));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtBool(static_cast<bool>(std::pow(tmpData,(static_cast<const DtDouble &>(other)).toDouble())));
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtBool::operator%(const IDt &other) const {
        throw Exception::NotImplementedException("Method not supported here!");
    }
}