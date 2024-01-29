//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_LINK_LINKWRAPPER_HPP
#define STREAM_V1_LINK_LINKWRAPPER_HPP

namespace Stream::V1::Link {
    template<typename InputTuple>
    class LinkWrapper {
    public:
        virtual ~LinkWrapper() = default;
        virtual void setInputTuple(InputTuple tuple) = 0;
        virtual void setInputTupleR(InputTuple& tuple) = 0;
    private:
    };
} // Stream::V1::Link

#endif //STREAM_V1_LINK_LINKWRAPPER_HPP
