//
// Created by Simon Stahmer on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATOR_ABSTRACTWRITER_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATOR_ABSTRACTWRITER_HPP

#include <sstream>
#include <string>
#include <utility>
#include <tuple>

namespace Apalinea::Operator::SinkOperator {
    class AbstractWriter {
    public:
        AbstractWriter() = default;
        ~AbstractWriter() = default;

        template<typename T>
        AbstractWriter& operator<<(const T& value) {
            write(std::to_string(value));
            return *this;
        }

        AbstractWriter& operator<<(const std::string& value) {
            write(value);
            return *this;
        }

        AbstractWriter& operator<<(std::ostream& (*manip)(std::ostream&)) {
            if (manip == static_cast<std::ostream& (*)(std::ostream&)>(std::endl)) {
                breakAndFlush(); // Insert newline
            }
            return *this;
        }

        template<typename... Args>
        void printf(const std::string& format, const Args&... args) {
            formatString(format, args...);
        }
    private:
        template<typename... Args>
        void formatString(const std::string& format, const Args&... args) {
            std::size_t argIndex = 0;
            std::ostringstream oss;

            for (std::size_t pos = 0; pos < format.size(); ++pos) {
                if (format[pos] == '{' && pos + 1 < format.size() && format[pos + 1] == '}') {
                    if constexpr (sizeof...(Args) > 0) {
                        if (argIndex < sizeof...(Args)) {
                            oss << std::get<argIndex>(std::forward_as_tuple(args...));
                            ++argIndex;
                        } else {
                            throw std::out_of_range("More placeholders than arguments in formatString");
                        }
                    } else {
                        throw std::invalid_argument("No arguments provided for placeholder");
                    }
                    ++pos; // Move past '{}'
                } else {
                    oss << format[pos];
                }
            }
            write(oss.str());
        }
    protected:
        virtual void write(const std::string& message) = 0;
        virtual void breakAndFlush() = 0;
    };
} // STREAM_V1_CORE_OPERATOR_SINKOPERATOR_ABSTRACTWRITER_HPP

#endif
