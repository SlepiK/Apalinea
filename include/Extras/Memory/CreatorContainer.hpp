#ifndef APALINEA_EXTRAS_MEMORY_CREATORCONTAINER_HPP
#define APALINEA_EXTRAS_MEMORY_CREATORCONTAINER_HPP

#include <memory>
#include <stdexcept>
#include "Extras/Memory/ICreator.hpp"
#include "Extras/Memory/DefaultCreator.hpp"

namespace Apalinea::Extras::Memory {
    template <typename CreatorType>
    class CreatorContainer {
    public:
        CreatorContainer() : vCreator(std::make_unique<DefaultCreator<CreatorType>>()) {
        }

        ~CreatorContainer() = default;

        ICreator<CreatorType>& getCreator() {
            if (!this->vCreator) {
                throw std::logic_error("Creator not set");
            }
            return *this->vCreator;
        }

        [[maybe_unused]] void setCreator(std::unique_ptr<ICreator<CreatorType>>&& creator) {
            this->vCreator = std::move(creator);
        }

    private:
        std::unique_ptr<ICreator<CreatorType>> vCreator;
    };
} // Apalinea::Extras::Memory

#endif //APALINEA_EXTRAS_MEMORY_CREATORCONTAINER_HPP
