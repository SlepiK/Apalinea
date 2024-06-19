//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_EXCEPTION_NOTIMPLEMENTEDEXCEPTION_HPP
#define STREAM_V1_EXCEPTION_NOTIMPLEMENTEDEXCEPTION_HPP

#include <stdexcept>

namespace Apalinea::Core::Exception {
    class NotImplementedException : public std::logic_error {
    public:
        explicit NotImplementedException(const std::string& err) : std::logic_error(err) {}
        explicit NotImplementedException(const char* err) : std::logic_error(err) {}
    };
}

#endif //STREAM_V1_EXCEPTION_NOTIMPLEMENTEDEXCEPTION_HPP
