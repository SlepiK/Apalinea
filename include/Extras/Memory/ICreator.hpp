#ifndef APALINEA_EXTRAS_MEMORY_ICREATOR_HPP
#define APALINEA_EXTRAS_MEMORY_ICREATOR_HPP

#include <cstddef>
#include "Extras/Memory/CreatorArgument.hpp"

namespace Apalinea::Extras::Memory {
    template <typename Type>
    class ICreator {
    public:
        virtual ~ICreator() = default;
        virtual Type* create(std::size_t size) = 0;
        virtual void destroy(Type* ptr, CreatorArgument arg = CreatorArgument::SINGLE) = 0;
    };
} // Apalinea::Extras::Memory

#endif //APALINEA_EXTRAS_MEMORY_ICREATOR_HPP
