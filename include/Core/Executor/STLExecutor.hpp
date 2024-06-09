//
// Created by SlepiK on 09.06.24.
//

#ifndef STREAM_V1_CORE_EXECUTOR_STLEXECUTOR_HPP
#define STREAM_V1_CORE_EXECUTOR_STLEXECUTOR_HPP

#include "IExecutor.hpp"

namespace Energyleaf::Stream::V1::Core::Executor {
    //ToDo: Implement a standard executor on basis of the stl with and without tasks.
    class STLExecutor : public IExecutor {
    public:
        explicit STLExecutor() {
        }

        ~STLExecutor() override {
        }

        void addTask(std::function<void()> task) override {
        }

        void joinTasks() override {
        }

        void shutdown() override {
        }
    private:
    };
}

#endif //STREAM_V1_CORE_EXECUTOR_STLEXECUTOR_HPP
