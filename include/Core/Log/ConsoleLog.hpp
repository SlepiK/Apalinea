//
// Created by SlepiK on 18.06.2024.
//

#ifndef STREAM_V1_CORE_LOG_CONSOLELOG_HPP
#define STREAM_V1_CORE_LOG_CONSOLELOG_HPP

#include "ILog.hpp"
#include <iostream>

namespace Energyleaf::Stream::V1::Core::Log {
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

        void log(LogLevel level, const struct tm* time, std::string_view file, int line, std::string_view message) final {
            if(line >= 0) {
                std::cout << "STREAM_LOG][" << level << "][" << file << ":" << line << "]:" << message << std::endl;
            } else {
                std::cout << "STREAM_LOG][" << level << "][" << file << "]:" << message << std::endl;
            }
        }
    private:
    protected:
    };
}

#endif //STREAM_V1_CORE_LOG_CONSOLELOG_HPP
