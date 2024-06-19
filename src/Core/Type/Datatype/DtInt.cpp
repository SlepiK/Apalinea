#include "Core/Type/Datatype/DtInt.hpp"

namespace Apalinea::Core::Type::Datatype {
    IDt *DtInt::operator+(const IDt &other) const {
        int tmpData = this->toInt();

        if (other.getIdentifier() == this->getIdentifier()) {//Int
            return new DtInt(tmpData + (static_cast<const DtInt &>(other)).toInt());
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtInt(tmpData + (static_cast<const DtUInt64 &>(other)).toUInt64());
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtInt(tmpData + (static_cast<const DtUInt32 &>(other)).toUInt32());
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtInt(tmpData + (static_cast<const DtUInt16 &>(other)).toUInt16());
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtInt(tmpData + (static_cast<const DtUInt8 &>(other)).toUInt8());
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtInt(tmpData + (static_cast<const DtInt64 &>(other)).toInt64());
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtInt(tmpData + (static_cast<const DtInt32 &>(other)).toInt32());
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtInt(tmpData + (static_cast<const DtInt16 &>(other)).toInt16());
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtInt(tmpData + (static_cast<const DtInt8 &>(other)).toInt8());
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {//SizeT
            return new DtInt(tmpData + (static_cast<const DtSizeT &>(other)).toSizeT());
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {//Bool
            return new DtInt(tmpData + (static_cast<const DtBool &>(other)).toBool());
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(static_cast<double>(tmpData) + static_cast<double>((static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(static_cast<double>(tmpData) + (static_cast<const DtDouble &>(other)).toDouble());
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtInt::operator-(const IDt &other) const {
        int tmpData = this->toInt();

        if (other.getIdentifier() == this->getIdentifier()) {//Int
            return new DtInt(tmpData - (static_cast<const DtInt &>(other)).toInt());
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtInt(tmpData - (static_cast<const DtUInt64 &>(other)).toUInt64());
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtInt(tmpData - (static_cast<const DtUInt32 &>(other)).toUInt32());
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtInt(tmpData - (static_cast<const DtUInt16 &>(other)).toUInt16());
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtInt(tmpData - (static_cast<const DtUInt8 &>(other)).toUInt8());
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtInt(tmpData - (static_cast<const DtInt64 &>(other)).toInt64());
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtInt(tmpData - (static_cast<const DtInt32 &>(other)).toInt32());
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtInt(tmpData - (static_cast<const DtInt16 &>(other)).toInt16());
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtInt(tmpData - (static_cast<const DtInt8 &>(other)).toInt8());
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {//SizeT
            return new DtInt(tmpData - (static_cast<const DtSizeT &>(other)).toSizeT());
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {//Bool
            return new DtInt(tmpData - (static_cast<const DtBool &>(other)).toBool());
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(static_cast<double>(tmpData) - static_cast<double>((static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(static_cast<double>(tmpData) - (static_cast<const DtDouble &>(other)).toDouble());
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtInt::operator*(const IDt &other) const {
        int tmpData = this->toInt();

        if (other.getIdentifier() == this->getIdentifier()) {//Int
            return new DtInt(tmpData * (static_cast<const DtInt &>(other)).toInt());
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtInt(tmpData * (static_cast<const DtUInt64 &>(other)).toUInt64());
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtInt(tmpData * (static_cast<const DtUInt32 &>(other)).toUInt32());
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtInt(tmpData * (static_cast<const DtUInt16 &>(other)).toUInt16());
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtInt(tmpData * (static_cast<const DtUInt8 &>(other)).toUInt8());
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtInt(tmpData * (static_cast<const DtInt64 &>(other)).toInt64());
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtInt(tmpData * (static_cast<const DtInt32 &>(other)).toInt32());
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtInt(tmpData * (static_cast<const DtInt16 &>(other)).toInt16());
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtInt(tmpData * (static_cast<const DtInt8 &>(other)).toInt8());
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {//SizeT
            return new DtInt(tmpData * (static_cast<const DtSizeT &>(other)).toSizeT());
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {//Bool
            return new DtInt(tmpData * (static_cast<const DtBool &>(other)).toBool());
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(static_cast<double>(tmpData) * static_cast<double>((static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(static_cast<double>(tmpData) * (static_cast<const DtDouble &>(other)).toDouble());
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtInt::operator/(const IDt &other) const {
        int tmpData = this->toInt();

        if (other.getIdentifier() == this->getIdentifier()) {//Int
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt &>(other)).toInt()));
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtUInt64 &>(other)).toUInt64()));
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtUInt32 &>(other)).toUInt32()));
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtUInt16 &>(other)).toUInt16()));
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtUInt8 &>(other)).toUInt8()));
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt64 &>(other)).toInt64()));
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt32 &>(other)).toInt32()));
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt16 &>(other)).toInt16()));
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt8 &>(other)).toInt8()));
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {//SizeT
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtSizeT &>(other)).toSizeT()));
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {//Bool
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtBool &>(other)).toBool()));
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(static_cast<double>(tmpData) / (static_cast<const DtDouble &>(other)).toDouble());
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtInt::operator^(const IDt &other) const {
        int tmpData = this->toInt();

        if (other.getIdentifier() == this->getIdentifier()) {//Int
            return new DtInt(std::pow(tmpData,(static_cast<const DtInt &>(other)).toInt()));
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtInt(std::pow(tmpData,(static_cast<const DtUInt64 &>(other)).toUInt64()));
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtInt(std::pow(tmpData,(static_cast<const DtUInt32 &>(other)).toUInt32()));
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtInt(std::pow(tmpData,(static_cast<const DtUInt16 &>(other)).toUInt16()));
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtInt(std::pow(tmpData,(static_cast<const DtUInt8 &>(other)).toUInt8()));
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtInt(std::pow(tmpData,(static_cast<const DtInt64 &>(other)).toInt64()));
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtInt(std::pow(tmpData,(static_cast<const DtInt32 &>(other)).toInt32()));
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtInt(std::pow(tmpData,(static_cast<const DtInt16 &>(other)).toInt16()));
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtInt(std::pow(tmpData,(static_cast<const DtInt8 &>(other)).toInt8()));
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {//SizeT
            return new DtInt(std::pow(tmpData,(static_cast<const DtSizeT &>(other)).toSizeT()));
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {//Bool
            return new DtInt(std::pow(tmpData,(static_cast<const DtBool &>(other)).toBool()));
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(std::pow(tmpData,(static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(std::pow(tmpData,(static_cast<const DtDouble &>(other)).toDouble()));
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtInt::operator%(const IDt &other) const {
        int tmpData = this->toInt();

        if (other.getIdentifier() == this->getIdentifier()) {//Int
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt &>(other)).toInt()));
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {//U64
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtUInt64 &>(other)).toUInt64()));
        } else if (other.getIdentifier() == DtUInt32::IDENTIFIER) {//U32
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtUInt32 &>(other)).toUInt32()));
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {//U16
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtUInt16 &>(other)).toUInt16()));
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {//U8
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtUInt8 &>(other)).toUInt8()));
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {//S64
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt64 &>(other)).toInt64()));
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {//S32
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt32 &>(other)).toInt32()));
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {//S16
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt16 &>(other)).toInt16()));
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {//S8
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt8 &>(other)).toInt8()));
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {//SizeT
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtSizeT &>(other)).toSizeT()));
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {//Bool
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtBool &>(other)).toBool()));
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(std::fmod(tmpData,(static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(std::fmod(tmpData,(static_cast<const DtDouble &>(other)).toDouble()));
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }
} // Apalinea::Core::Type::Datatype