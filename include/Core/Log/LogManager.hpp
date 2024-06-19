//
// Created by SlepiK on 18.06.2024.
//

#ifndef STREAM_V1_CORE_LOG_LOGMANAGER_HPP
#define STREAM_V1_CORE_LOG_LOGMANAGER_HPP

#include <string_view>
#include <vector>
#include <memory>
#include "Core/Log/ILog.hpp"
#include "Core/Log/LogLevel.hpp"

namespace Apalinea::Core::Log {

    inline std::string getFilename(const std::string& file) {
        size_t seperator = file.find_last_of("/\\");
        return seperator != std::string::npos ? file.substr(seperator + 1) : file;
    }

    class LogManager {
    public:
        static void log(LogLevel level, std::string_view file, int line, std::string_view message) {
            time_t tTime;
            time(&tTime);
            struct tm* logTime = localtime(&tTime);

            for(LogVector::iterator iterator = logs.begin(); iterator != logs.end(); ++iterator) {
                iterator->get()->log(level,logTime,file,line,message);
            }
        }

        static bool haveLog() {
            return !logs.empty();
        }

        static void log(LogLevelCategory level, std::string_view file, int line, std::string_view message) {
            time_t tTime;
            time(&tTime);
            struct tm* logTime = localtime(&tTime);

            for(LogVector::iterator iterator = logs.begin(); iterator != logs.end(); ++iterator) {
                iterator->get()->log(LogLevel(level),logTime,file,line,message);
            }
        }

        static void addLog(std::unique_ptr<ILog>&& log) {
            log->open();
            logs.push_back(std::move(log));
        }

        static void close() {
            for(LogVector::iterator iterator = logs.begin(); iterator != logs.end(); ++iterator) {
                iterator->get()->close();
            }
        }

        static void flush() {
            for(LogVector::iterator iterator = logs.begin(); iterator != logs.end(); ++iterator) {
                iterator->get()->flush();
            }
        }


    private:
        using LogVector = typename std::vector<std::unique_ptr<ILog>>;
        static LogVector logs;
    protected:
    };
}

#endif //STREAM_V1_CORE_LOG_LOGMANAGER_HPP
