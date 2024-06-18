//
// Created by SlepiK on 18.06.2024.
//

#ifndef STREAM_V1_CORE_LOG_LOGLEVELCATEGORY_HPP
#define STREAM_V1_CORE_LOG_LOGLEVELCATEGORY_HPP

#include <map>
#include <ostream>
#include <string_view>

namespace Energyleaf::Stream::V1::Core::Log {
    enum class LogLevelCategory {
        INFORMATION,
        WARNING,
        ERROR,
        CRITICAL,
        MAX
    };

    const std::map<LogLevelCategory,std::string_view> LogLevelCategoryMap{
        {LogLevelCategory::INFORMATION, "Information"},
        {LogLevelCategory::WARNING, "Warning"},
        {LogLevelCategory::ERROR, "Error"},
        {LogLevelCategory::CRITICAL, "Critical"},
        {LogLevelCategory::MAX, "Max"}
    };

    inline std::ostream& operator<< (std::ostream& os, const LogLevelCategory& obj) {
        os << LogLevelCategoryMap.at(obj);
        return os;
    }

    inline std::string_view toString(const LogLevelCategory& obj) {
        return LogLevelCategoryMap.at(obj);
    }
}

#endif //STREAM_V1_CORE_LOG_LOGLEVELCATEGORY_HPP
