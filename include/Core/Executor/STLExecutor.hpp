#ifndef APALINEA_CORE_EXECUTOR_STLEXECUTOR_HPP
#define APALINEA_CORE_EXECUTOR_STLEXECUTOR_HPP

#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include "Core/Executor/IExecutor.hpp"

namespace Apalinea::Core::Executor {
    class STLExecutor : public IExecutor {
    public:
        STLExecutor() : STLExecutor(2) {
        }

        explicit STLExecutor(std::size_t numThreads) : numTasksInProgress(0), stop(false) {
            for(size_t i = 0; i < numThreads; ++i)
                workers.emplace_back([this]() { this->threadEntry(); });
        }

        ~STLExecutor() override {
            {
                std::unique_lock<std::mutex> lock(this->mutex);
                stop = true;
            }
            cv.notify_all();
            for(auto& worker : workers) worker.join();
        }

        void addTask(std::function<void()> task) override {
            {
                std::unique_lock<std::mutex> lock(this->mutex);
                ++numTasksInProgress;
                tasks.push(std::move(task));
            }
            cv.notify_one();
        }

        void joinTasks() override {
            std::unique_lock<std::mutex> lock(this->mutex);
            this->cv.wait(lock, [this]() { return this->numTasksInProgress == 0; });
        }

        void shutdown() override {
            {
                std::unique_lock<std::mutex> lock(this->mutex);
                stop = true;
            }
            cv.notify_all();
            for(auto& worker : workers) worker.join();
        }

    private:
        std::vector<std::thread> workers;
        std::queue<std::function<void()>> tasks;
        std::atomic<int> numTasksInProgress;
        std::atomic_bool stop;
        std::mutex mutex;
        std::condition_variable cv;

        void threadEntry() {
            std::function<void()> task;
            while(true) {
                {
                    std::unique_lock<std::mutex> lock(this->mutex);
                    this->cv.wait(lock, [this]() { return this->stop || !tasks.empty(); });
                    if(!tasks.empty()) {
                        task = std::move(tasks.front());
                        tasks.pop();
                    }  else if(stop) return;
                }
                task();
                std::unique_lock<std::mutex> lock(this->mutex);
                --numTasksInProgress;
                if(numTasksInProgress == 0) cv.notify_all();
            }
        }
    };
} // Apalinea::Core::Executor

#endif //APALINEA_CORE_EXECUTOR_STLEXECUTOR_HPP
