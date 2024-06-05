//
// Created by SlepiK on 13.02.24.
//

#ifndef ENERGYLEAF_STREAM_V1_EXTRAS_MEMORY_ICREATOR_HPP
#define ENERGYLEAF_STREAM_V1_EXTRAS_MEMORY_ICREATOR_HPP

#include <cstddef>
#include <Extras/Memory/CreatorArgument.hpp>

namespace Energyleaf::Stream::V1::Extras::Memory {
    template <typename Type>
    class ICreator {
    public:
        virtual ~ICreator() = default;
        virtual Type* create(std::size_t size) = 0;
        virtual void destroy(Type* ptr, CreatorArgument arg = CreatorArgument::SINGLE) = 0;
    };
}

#endif // ENERGYLEAF_STREAM_V1_EXTRAS_MEMORY_ICREATOR_HPP
