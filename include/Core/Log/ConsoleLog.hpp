//
// Created by SlepiK on 18.06.2024.
//

#ifndef STREAM_V1_CORE_LOG_CONSOLELOG_HPP
#define STREAM_V1_CORE_LOG_CONSOLELOG_HPP

#include <iostream>
#include "Core/Log/ILog.hpp"

namespace Apalinea::Core::Log {
    class ConsoleLog : public ILog {
    public:
        ConsoleLog() = default;
        ~ConsoleLog() override = default;


        void open() final {
        }

        void close() final {
        }

        void flush() final {
            std::cout << std::flush;
        }

        void log(LogLevel level, std::tm* time, std::string_view file, int line, std::string_view message) final {
            if(line >= 0) {
                std::cout << "APALINEA_LOG][" << time->tm_mday << "." << time->tm_mon + 1 << "." << time->tm_year + + 1900 << "-" << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << "][" << level << "][" << file << ":" << line << "]:" << message << std::endl;
            } else {
                std::cout << "APALINEA_LOG][" << time->tm_mday << "." << time->tm_mon + 1 << "." << time->tm_year + + 1900 << "-" << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << "][" << level << "][" << file << "]:" << message << std::endl;
            }
        }
    private:
    protected:
    };
}

#endif //STREAM_V1_CORE_LOG_CONSOLELOG_HPP
