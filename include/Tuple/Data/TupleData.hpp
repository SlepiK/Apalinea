//
// Created by simon on 27.01.2024.
//

#ifndef STREAM_V1_TUPLE_TUPLEDATA_HPP
#define STREAM_V1_TUPLE_TUPLEDATA_HPP

#include <string>

namespace Stream::V1::Tuple {

    template<typename Tdata>
    class TupleData {
    public:
    private:
        Tdata vData;
        std::string vName;
    protected:
    };

} // Stream::V1::Tuple

#endif //STREAM_V1_TUPLE_TUPLEDATA_HPP
