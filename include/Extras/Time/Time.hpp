#ifndef APALINEA_EXTRAS_TIME_TIME_HPP
#define APALINEA_EXTRAS_TIME_TIME_HPP

#include <chrono>

namespace Apalinea::Extras::Time {
    class Time {
    public:
        static std::chrono::steady_clock::time_point getCurrentTimePoint() {
            return std::chrono::steady_clock::now();
        }
    };
}

#endif //APALINEA_EXTRAS_TIME_TIME_HPP
