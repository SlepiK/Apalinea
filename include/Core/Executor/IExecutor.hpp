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
        virtual void addTask(std::function<void()> task) = 0;
        virtual void joinTasks() = 0;
        virtual void shutdown() = 0;
    };
}

#endif //STREAM_V1_CORE_EXECUTOR_IEXECUTOR_HPP
