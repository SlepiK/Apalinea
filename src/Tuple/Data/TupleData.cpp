//
// Created by SlepiK on 27.01.2024.
//

#include "../../../include/Tuple/Data/TupleData.hpp"

namespace Stream::V1::Tuple {
    template <typename Tdata>
    Tdata TupleData<Tdata>::getData() const {
        return this->vData;
    }

    template <typename Tdata>
    std::string_view TupleData<Tdata>::getName() const {
        return this->vName;
    }

    template <typename Tdata>
    void TupleData<Tdata>::updateName(std::string&& name) {
        this->vName = std::move(name);
    }
} // Stream::V1::Tuple