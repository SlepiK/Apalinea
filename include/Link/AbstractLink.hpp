//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_ABSTRACTLINK_HPP
#define STREAM_V1_LINK_ABSTRACTLINK_HPP

#include "ILink.hpp"
#include "Trait/LinkTrait.hpp"

namespace Stream::V1::Link {

    class AbstractLink : public ILink {
    public:
        AbstractLink() : vProcessed(false), vProcessing(false) {
        }

        ~AbstractLink() override = default;

        [[nodiscard]] bool isProcessing() const override;

        [[nodiscard]] bool isProcessed() const override;

    private:
    protected:
        bool vProcessing;
        bool vProcessed;
    };

} // Stream::V1::Link

#endif //STREAM_V1_LINK_ABSTRACTLINK_HPP
