//
// Created by Simon Stahmer on 29.01.24.
//

#ifndef ENERGLEAF_STREAM_V1_TYPES_EMPTYTYPE_HPP
#define ENERGLEAF_STREAM_V1_TYPES_EMPTYTYPE_HPP

namespace Energyleaf::Stream::V1::Types {
    /**
     * This class represents a empty object or empty type, because void as type is not direct allowed in this library!
     */
    class EmptyType {
    public:
        EmptyType() = default;
        virtual ~EmptyType() = default;
    };
}

#endif //ENERGLEAF_STREAM_V1_TYPES_EMPTYTYPE_HPP
