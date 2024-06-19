//
// Created by SlepiK on 18.06.2024.
//

#ifndef STREAM_V1_CORE_LOG_LOGLEVEL_HPP
#define STREAM_V1_CORE_LOG_LOGLEVEL_HPP

#include <ostream>
#include "Core/Log/LogLevelCategory.hpp"

namespace Apalinea::Core::Log {
    class LogLevel {
    public:
        LogLevel() {
            vLogLevelCategory = LogLevelCategory::INFORMATION;
        }

        explicit LogLevel(LogLevelCategory logLevelCategory) {
            vLogLevelCategory = logLevelCategory;
        }

        friend inline bool operator< (const LogLevel& lhs, const LogLevel& rhs) {
            return lhs.vLogLevelCategory < rhs.vLogLevelCategory;
        }

        friend inline bool operator<= (const LogLevel& lhs, const LogLevel& rhs) {
            return lhs.vLogLevelCategory <= rhs.vLogLevelCategory;
        }

        friend inline bool operator> (const LogLevel& lhs, const LogLevel& rhs) {
            return lhs.vLogLevelCategory > rhs.vLogLevelCategory;
        }

        friend inline bool operator>= (const LogLevel& lhs, const LogLevel& rhs) {
            return lhs.vLogLevelCategory >= rhs.vLogLevelCategory;
        }

        friend inline bool operator== (const LogLevel& lhs, const LogLevel& rhs) {
            return lhs.vLogLevelCategory == rhs.vLogLevelCategory;
        }

        friend inline bool operator != (const LogLevel& lhs, const LogLevel& rhs) {
            return lhs.vLogLevelCategory != rhs.vLogLevelCategory;
        }

        friend std::ostream& operator<< (std::ostream& os, const LogLevel& obj) {
            os << obj.vLogLevelCategory;
            return os;
        }

        [[nodiscard]] std::string_view print() const {
            return toString(vLogLevelCategory);
        }

        LogLevelCategory getLogLevelCategory() {
            return vLogLevelCategory;
        }

    private:
        LogLevelCategory vLogLevelCategory;
    protected:
    };
}

#endif //STREAM_V1_CORE_LOG_LOGLEVEL_HPP
