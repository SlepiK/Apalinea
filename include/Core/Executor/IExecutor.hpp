#ifndef APALINEA_CORE_EXECUTOR_IEXECUTOR_HPP
#define APALINEA_CORE_EXECUTOR_IEXECUTOR_HPP

#include <functional>

namespace Apalinea::Core::Executor {
    class IExecutor {
    public:
        virtual ~IExecutor() = default;

        virtual void addTask(std::function<void()> task) = 0;

        virtual void joinTasks() = 0;

        virtual void shutdown() = 0;
    };
} // Apalinea::Core::Executor

#endif //APALINEA_CORE_EXECUTOR_IEXECUTOR_HPP
