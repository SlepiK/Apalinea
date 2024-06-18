//
// Created by SlepiK on 18.06.24.
//

#ifndef STREAM_V1_CORE_LOG_ILOG_HPP
#define STREAM_V1_CORE_LOG_ILOG_HPP

#include <string_view>
#include "LogLevel.hpp"

namespace Energyleaf::Stream::V1::Core::Log {
    class ILog {
    public:
        ILog() = default;
        virtual ~ILog() = default;

        virtual void open() = 0;
        virtual void close() = 0;
        virtual void flush() = 0;

        virtual void log(LogLevel level, const struct tm* time, std::string_view file, int line, std::string_view message) = 0;
    private:
    protected:
    };
}

#endif //STREAM_V1_CORE_LOG_ILOG_HPP