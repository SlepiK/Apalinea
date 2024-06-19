//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_ABSTRACTLINK_HPP
#define STREAM_V1_LINK_ABSTRACTLINK_HPP

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
            vProcessing(false) ,
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

    private:
    protected:
        bool vProcessing;
        bool vProcessed;
        bool vNewDataAvailable;
        Core::Operator::OperatorProcessState vState;
        std::shared_ptr<Core::Executor::IExecutor> executor;
    };

} // Stream::V1::Link

#endif //STREAM_V1_LINK_ABSTRACTLINK_HPP
