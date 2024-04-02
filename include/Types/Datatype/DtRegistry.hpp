//
// Created by SlepiK on 15.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTREGISTRY_HPP
#define STREAM_V1_TYPES_DATATYPE_DTREGISTRY_HPP

#include <unordered_map>
#include <string_view>
#include <stdexcept>

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtRegistry {
    public:
        using DtRegistryIndex = unsigned int;
        using DtRegistryIdentifier = typename std::string_view;

        static DtRegistryIndex reg(DtRegistryIdentifier identifier) {
            auto it = dtMap.find(identifier);
            if(it == dtMap.end()) {
                DtRegistryIndex index = dtCurrentIndex++;
                dtMap[identifier] = index;
                return index;
            } else {
                //Already registered
                return it->second;
            }
        }

        static DtRegistryIndex get(DtRegistryIdentifier identifier) {
            auto it = dtMap.find(identifier);
            if(it != dtMap.end()) {
                return it->second;
            } else {
                throw std::runtime_error("Requested datatype is not registered!");
            }
        }

        static void unreg(DtRegistryIdentifier identifier) {
            auto it = dtMap.find(identifier);
            if(it != dtMap.end()) {
                dtMap.erase(it);
            } else {
                throw std::runtime_error("Requested datatype to unregister is not in stored in the registry!");
            }
        }

        static bool isRegistered(DtRegistryIdentifier identifier) {
            return dtMap.find(identifier) != dtMap.end();
        }
    private:
        static std::unordered_map<DtRegistryIdentifier, DtRegistryIndex> dtMap;
        static DtRegistryIndex dtCurrentIndex;
    };

    //Special identifier, when a type cant be set directly and will be set during runtime!
    static constexpr DtRegistry::DtRegistryIdentifier UNDEFINED{"UNDEFINED"};

}

#endif //STREAM_V1_TYPES_DATATYPE_DTREGISTRY_HPP
