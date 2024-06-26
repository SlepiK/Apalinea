#ifndef APALINEA_CORE_LINK_ABSTRACTLINK_HPP
#define APALINEA_CORE_LINK_ABSTRACTLINK_HPP

#include <utility>
#include "Core/Link/ILink.hpp"
#include "Core/Link/Trait/LinkTrait.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Executor/IExecutor.hpp"
#include "Core/Log/LogManager.hpp"

namespace Apalinea::Core::Link {
    class AbstractLink : public ILink {
    public:
        explicit AbstractLink(std::shared_ptr<Core::Executor::IExecutor> executor) :
            vProcessed(false),
            vProcessing(false),
            vNewDataAvailable(false),
            vState(Operator::OperatorProcessState::CONTINUE),
            executor(std::move(executor)) {
        }

        ~AbstractLink() override = default;

        [[nodiscard]] bool isProcessing() const override {
            return this->vProcessing;
        }

        [[nodiscard]] bool isProcessed() const override {
            return this->vProcessed;
        }

    protected:
        bool vProcessing;
        bool vProcessed;
        bool vNewDataAvailable;
        Core::Operator::OperatorProcessState vState;
        std::shared_ptr<Core::Executor::IExecutor> executor;
    };
} // Apalinea::Core::Link

#endif //APALINEA_CORE_LINK_ABSTRACTLINK_HPP
