//
// Created by SlepiK on 27.01.2024.
//

#include "../../../include/Tuple/Item/Item.hpp"

namespace Stream::V1::Tuple {
    template <typename TData>
    TData Item<TData>::getData() const {
        return this->vData;
    }

    template <typename TData>
    std::string_view Item<TData>::getName() const {
        return this->vName;
    }

    std::string_view Item<void>::getName() const {
        return this->vName;
    }

    template <typename TData>
    void Item<TData>::updateName(std::string&& name) {
        this->vName = std::move(name);
    }

    void Item<void>::updateName(std::string&& name) {
        this->vName = std::move(name);
    }
} // Stream::V1::Tuple