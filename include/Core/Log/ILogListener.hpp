//
// Created by SlepiK on 18.06.2024.
//

#ifndef STREAM_V1_CORE_LOG_ILOGLISTENER_HPP
#define STREAM_V1_CORE_LOG_ILOGLISTENER_HPP

#include <string_view>
#include "LogLevel.hpp"

namespace Energyleaf::Stream::V1::Core::Log {
    class ILogListener {
    public:
        ILogListener() = default;
        virtual ~ILogListener() = default;

        virtual void open() = 0;
        virtual void close() = 0;
        virtual void flush() = 0;

        virtual void log(LogLevel level, const struct tm* time, std::string_view file, int line, std::string_view message) = 0;
    private:
    protected:
    };
}

#endif //STREAM_V1_CORE_LOG_ILOGLISTENER_HPP