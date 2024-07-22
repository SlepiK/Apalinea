#ifndef APALINEA_CORE_LOG_LOGMANAGER_HPP
#define APALINEA_CORE_LOG_LOGMANAGER_HPP

#include <string_view>
#include <vector>
#include <memory>
#include <ctime>
#include "Core/Log/ILog.hpp"
#include "Core/Log/LogLevel.hpp"

namespace Apalinea::Core::Log {
    inline std::string getFilename(const std::string& file) {
        size_t separator = file.find_last_of("/\\");
        return separator != std::string::npos ? file.substr(separator + 1) : file;
    }

    class LogManager {
    public:
        static void log(LogLevel level, std::string_view file, int line, std::string_view message) {
            if(level.getLogLevelCategory() == Apalinea::Core::Log::LogLevelCategory::HEARTBEAT &&
                !Apalinea::Core::Log::LogManager::printHeartbeat) return;
            std::time_t tTime = std::time(nullptr);
            std::tm* logTime = std::localtime(&tTime);

            for(auto & log : logs) {
                log->log(level,logTime,file,line,message);
            }
        }

        [[nodiscard]] static bool haveLog() {
            return !logs.empty();
        }

        static void log(LogLevelCategory level, std::string_view file, int line, std::string_view message) {
            if(level == Apalinea::Core::Log::LogLevelCategory::HEARTBEAT &&
               !Apalinea::Core::Log::LogManager::printHeartbeat) return;
            time_t tTime;
            time(&tTime);
            struct tm* logTime = localtime(&tTime);

            for(auto & log : logs) {
                log->log(LogLevel(level),logTime,file,line,message);
            }
        }

        [[maybe_unused]] static void setPrintHeartbeat(bool print) {
            Apalinea::Core::Log::LogManager::printHeartbeat = print;
        }

        [[maybe_unused]] [[nodiscard]] static bool getPrintHeartbeat() {
            return Apalinea::Core::Log::LogManager::printHeartbeat;
        }

        static void addLog(std::unique_ptr<ILog>&& log) {
            log->open();
            logs.push_back(std::move(log));
        }

        [[maybe_unused]] static void close() {
            for(auto & log : logs) {
                log->close();
            }
        }

        [[maybe_unused]] static void flush() {
            for(auto & log : logs) {
                log->flush();
            }
        }

    private:
        using LogVector = typename std::vector<std::unique_ptr<ILog>>;
        static LogVector logs;
        static bool printHeartbeat;
    };
} // Apalinea::Core::Log

#endif //APALINEA_CORE_LOG_LOGMANAGER_HPP
