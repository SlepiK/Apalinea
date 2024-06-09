//
// Created by SlepiK on 28.01.24.
//

#ifndef STREAM_V1_LINK_ABSTRACTLINK_HPP
#define STREAM_V1_LINK_ABSTRACTLINK_HPP

#include <utility>

#include "ILink.hpp"
#include "Trait/LinkTrait.hpp"
#include "Tuple/Tuple.hpp"
#include "Core/Executor/IExecutor.hpp"

namespace Energyleaf::Stream::V1::Link {

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
        Operator::OperatorProcessState vState;
        std::shared_ptr<Core::Executor::IExecutor> executor;
    };

} // Stream::V1::Link

#endif //STREAM_V1_LINK_ABSTRACTLINK_HPP
