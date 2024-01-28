//
// Created by simon on 27.01.2024.
//

#include "Operator/AbstractOperator.hpp"

namespace Stream::V1::Operator {
    bool AbstractOperator::isProcessing() const {
        return this->vProcessing;
    }

    bool AbstractOperator::isProcessed() const {
        return this->vProcessed;
    }
} // Stream::V1::Operator