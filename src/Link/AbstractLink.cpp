//
// Created by SlepiK on 28.01.24.
//

#include "Link/AbstractLink.hpp"

namespace Stream::V1::Link {
    bool AbstractLink::isProcessing() const {
        return this->vProcessing;
    }

    bool AbstractLink::isProcessed() const {
        return this->vProcessed;
    }
} // Stream::V1::Link