//
// Created by simon on 27.01.2024.
//

#ifndef STREAM_V1_TUPLE_TUPLEDATA_HPP
#define STREAM_V1_TUPLE_TUPLEDATA_HPP

#include <string>
#include <string_view>
#include <utility>

namespace Stream::V1::Tuple {

    template<typename Tdata>
    class TupleData {
    public:

        TupleData(std::string&& name, Tdata&& data)
            : vName(std::move(name)), vData(std::forward<Tdata>(data)) {
        }

        TupleData(TupleData&& other)
            : vName(std::move(other.vName)), vData(std::move(other.vData)) {
        }

        TupleData(TupleData&& other, Tdata&& data)
            : vName(std::move(other.vName)), vData(std::forward<Tdata>(data)) {
        }

        virtual ~TupleData() = default;

        Tdata getData() const;

        std::string_view getName() const;

        void updateName(std::string&& name);

    private:
        const Tdata vData;
        std::string vName;
    };

} // Stream::V1::Tuple

#endif //STREAM_V1_TUPLE_TUPLEDATA_HPP
