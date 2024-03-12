//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_IDT_HPP
#define STREAM_V1_TYPES_DATATYPE_IDT_HPP

#include <unordered_set>
#include <string_view>
#include <vector>
#include <memory>

namespace Energyleaf::Stream::V1::Types::Datatype {
    static std::vector<std::string_view> combine(std::vector<std::string_view> t1, std::vector<std::string_view> t2) {
        t1.insert(t1.end(),t2.begin(),t2.end());
        return t1;
    }

    class IDt {
    public:
        explicit IDt(std::vector<std::string_view> datatypes) : datatypes(datatypes.begin(),datatypes.end()) {
        }
        virtual ~IDt() = default;
        [[nodiscard]] virtual std::unique_ptr<IDt> copy() const = 0;
        bool isCastAble(std::string_view datatype) const {
            return this->datatypes.find(datatype) != this->datatypes.end();
        }
    private:
        const std::unordered_set<std::string_view> datatypes;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_IDT_HPP
