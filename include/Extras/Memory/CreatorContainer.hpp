//
// Created by SlepiK on 13.02.24.
//

#ifndef ENERGYLEAF_STREAM_V1_EXTRAS_MEMORY_CREATORCONTAINER_HPP
#define ENERGYLEAF_STREAM_V1_EXTRAS_MEMORY_CREATORCONTAINER_HPP

#include <Extras/Memory/ICreator.hpp>
#include <Extras/Memory/DefaultCreator.hpp>
#include <memory>

namespace Energyleaf::Stream::V1::Extras::Memory {
    template <typename CreatorType>
    class CreatorContainer {
    public:
        CreatorContainer() : vCreator(std::make_unique<DefaultCreator<CreatorType>>()) {
        }

        ~CreatorContainer() {
        }

        ICreator<CreatorType>& getCreator() {
            if (!this->vCreator) {
                throw std::logic_error("Creator not set");
            }
            return *this->vCreator;
        }

        void setCreator(std::unique_ptr<ICreator<CreatorType>>&& creator) {
            this->vCreator = std::move(creator);
        }

    private:
        std::unique_ptr<ICreator<CreatorType>> vCreator;
    };
}

#endif // ENERGYLEAF_STREAM_V1_EXTRAS_MEMORY_ICREATORCONTAINER_HPP
