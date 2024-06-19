#ifndef APALINEA_CORE_LOG_ILOG_HPP
#define APALINEA_CORE_LOG_ILOG_HPP

#include <string_view>
#include <ctime>
#include "Core/Log/LogLevel.hpp"

namespace Apalinea::Core::Log {
    class ILog {
    public:
        ILog() = default;
        virtual ~ILog() = default;

        virtual void open() = 0;

        virtual void close() = 0;

        virtual void flush() = 0;

        virtual void log(LogLevel level, std::tm* time, std::string_view file, int line, std::string_view message) = 0;
    };
} // Apalinea::Core::Log

#endif //APALINEA_CORE_LOG_ILOG_HPP
