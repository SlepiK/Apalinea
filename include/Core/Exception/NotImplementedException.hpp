#ifndef APALINEA_CORE_EXCEPTION_NOTIMPLEMENTEDEXCEPTION_HPP
#define APALINEA_CORE_EXCEPTION_NOTIMPLEMENTEDEXCEPTION_HPP

#include <stdexcept>

namespace Apalinea::Core::Exception {
    class NotImplementedException : public std::logic_error {
    public:
        [[maybe_unused]] explicit NotImplementedException(const std::string& err) : std::logic_error(err) {}
        explicit NotImplementedException(const char* err) : std::logic_error(err) {}
    };
} // Apalinea::Core::Exception

#endif //APALINEA_CORE_EXCEPTION_NOTIMPLEMENTEDEXCEPTION_HPP
