#include "Core/Type/Datatype/DtUInt32.hpp"

namespace Apalinea::Core::Type::Datatype {
    IDt *DtUInt32::operator+(const IDt &other) const {
        uint32_t tmpData = this->toUInt32();

        if (other.getIdentifier() == this->getIdentifier()) {
            return new DtUInt32(tmpData + (static_cast<const DtUInt32 &>(other)).toUInt32());
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtUInt64 &>(other)).toUInt64());
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtUInt16 &>(other)).toUInt16());
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtUInt8 &>(other)).toUInt8());
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtInt64 &>(other)).toInt64());
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtInt32 &>(other)).toInt32());
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtInt16 &>(other)).toInt16());
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtInt8 &>(other)).toInt8());
        } else if (other.getIdentifier() == DtInt::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtInt &>(other)).toInt());
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtSizeT &>(other)).toSizeT());
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {
            return new DtUInt32(tmpData + (static_cast<const DtBool &>(other)).toBool());
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(static_cast<double>(tmpData) + static_cast<double>((static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(static_cast<double>(tmpData) + (static_cast<const DtDouble &>(other)).toDouble());
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtUInt32::operator-(const IDt &other) const {
        uint32_t tmpData = this->toUInt32();

        if (other.getIdentifier() == this->getIdentifier()) {
            return new DtUInt32(tmpData - (static_cast<const DtUInt32 &>(other)).toUInt32());
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtUInt64 &>(other)).toUInt64());
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtUInt16 &>(other)).toUInt16());
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtUInt8 &>(other)).toUInt8());
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtInt64 &>(other)).toInt64());
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtInt32 &>(other)).toInt32());
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtInt16 &>(other)).toInt16());
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtInt8 &>(other)).toInt8());
        } else if (other.getIdentifier() == DtInt::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtInt &>(other)).toInt());
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtSizeT &>(other)).toSizeT());
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {
            return new DtUInt32(tmpData - (static_cast<const DtBool &>(other)).toBool());
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(static_cast<double>(tmpData) - static_cast<double>((static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(static_cast<double>(tmpData) - (static_cast<const DtDouble &>(other)).toDouble());
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtUInt32::operator*(const IDt &other) const {
        uint32_t tmpData = this->toUInt32();

        if (other.getIdentifier() == this->getIdentifier()) {
            return new DtUInt32(tmpData * (static_cast<const DtUInt32 &>(other)).toUInt32());
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtUInt64 &>(other)).toUInt64());
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtUInt16 &>(other)).toUInt16());
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtUInt8 &>(other)).toUInt8());
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtInt64 &>(other)).toInt64());
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtInt32 &>(other)).toInt32());
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtInt16 &>(other)).toInt16());
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtInt8 &>(other)).toInt8());
        } else if (other.getIdentifier() == DtInt::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtInt &>(other)).toInt());
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtSizeT &>(other)).toSizeT());
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {
            return new DtUInt32(tmpData * (static_cast<const DtBool &>(other)).toBool());
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(static_cast<double>(tmpData) * static_cast<double>((static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(static_cast<double>(tmpData) * (static_cast<const DtDouble &>(other)).toDouble());
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtUInt32::operator/(const IDt &other) const {
        uint32_t tmpData = this->toUInt32();

        if (other.getIdentifier() == this->getIdentifier()) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtUInt32 &>(other)).toUInt32()));
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtUInt64 &>(other)).toUInt64()));
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtUInt16 &>(other)).toUInt16()));
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtUInt8 &>(other)).toUInt8()));
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt64 &>(other)).toInt64()));
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt32 &>(other)).toInt32()));
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt16 &>(other)).toInt16()));
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt8 &>(other)).toInt8()));
        } else if (other.getIdentifier() == DtInt::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtInt &>(other)).toInt()));
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtSizeT &>(other)).toSizeT()));
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtBool &>(other)).toBool()));
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(static_cast<double>(tmpData) / static_cast<double>((static_cast<const DtFloat &>(other)).toFloat()));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(static_cast<double>(tmpData) / (static_cast<const DtDouble &>(other)).toDouble());
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtUInt32::operator^(const IDt &other) const {
        uint32_t tmpData = this->toUInt32();

        if (other.getIdentifier() == this->getIdentifier()) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtUInt32 &>(other)).toUInt32())));
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtUInt64 &>(other)).toUInt64())));
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtUInt16 &>(other)).toUInt16())));
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtUInt8 &>(other)).toUInt8())));
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtInt64 &>(other)).toInt64())));
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtInt32 &>(other)).toInt32())));
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtInt16 &>(other)).toInt16())));
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtInt8 &>(other)).toInt8())));
        } else if (other.getIdentifier() == DtInt::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtInt &>(other)).toInt())));
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtSizeT &>(other)).toSizeT())));
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {
            return new DtUInt32(static_cast<uint32_t>(std::pow(tmpData,(static_cast<const DtBool &>(other)).toBool())));
        } else if(other.getIdentifier() == DtFloat::IDENTIFIER) {//Float
            return new DtDouble(std::pow(static_cast<double>(tmpData),static_cast<double>((static_cast<const DtFloat &>(other)).toFloat())));
        } else if(other.getIdentifier() == DtDouble::IDENTIFIER) {//Double
            return new DtDouble(std::pow(static_cast<double>(tmpData),(static_cast<const DtDouble &>(other)).toDouble()));
        } else {
            throw std::invalid_argument("Cant calculate with the given two arguments!");
        }
    }

    IDt *DtUInt32::operator%(const IDt &other) const {
        uint32_t tmpData = this->toUInt32();

        if (other.getIdentifier() == this->getIdentifier()) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtUInt32 &>(other)).toUInt32()));
        } else if (other.getIdentifier() == DtUInt64::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtUInt64 &>(other)).toUInt64()));
        } else if (other.getIdentifier() == DtUInt16::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtUInt16 &>(other)).toUInt16()));
        } else if (other.getIdentifier() == DtUInt8::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtUInt8 &>(other)).toUInt8()));
        } else if (other.getIdentifier() == DtInt64::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt64 &>(other)).toInt64()));
        } else if (other.getIdentifier() == DtInt32::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt32 &>(other)).toInt32()));
        } else if (other.getIdentifier() == DtInt16::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt16 &>(other)).toInt16()));
        } else if (other.getIdentifier() == DtInt8::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt8 &>(other)).toInt8()));
        } else if (other.getIdentifier() == DtInt::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtInt &>(other)).toInt()));
        } else if (other.getIdentifier() == DtSizeT::IDENTIFIER) {
            return new DtDouble(static_cast<double>(tmpData % (static_cast<const DtSizeT &>(other)).toSizeT()));
        } else if (other.getIdentifier() == DtBool::IDENTIFIER) {
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