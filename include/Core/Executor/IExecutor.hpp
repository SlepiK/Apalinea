//
// Created by SlepiK on 06.06.24.
//

#ifndef STREAM_V1_CORE_EXECUTOR_IEXECUTOR_HPP
#define STREAM_V1_CORE_EXECUTOR_IEXECUTOR_HPP

#include <functional>

namespace Energyleaf::Stream::V1::Core::Executor {
    class IExecutor {
    public:
        virtual ~IExecutor() = default;
        virtual void task(std::function<void()> task) = 0;
        virtual void join() = 0;
    };
}

#endif //STREAM_V1_CORE_EXECUTOR_IEXECUTOR_HPP
