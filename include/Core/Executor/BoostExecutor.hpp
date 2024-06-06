//
// Created by SlepiK on 06.06.24.
//

#ifndef STREAM_V1_CORE_EXECUTOR_BOOSTEXECUTOR_HPP
#define STREAM_V1_CORE_EXECUTOR_BOOSTEXECUTOR_HPP

#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>

#include "IExecutor.hpp"

namespace Energyleaf::Stream::V1::Core::Executor {
    class BoostExecutor : public IExecutor {
    public:
        explicit BoostExecutor(std::size_t numThreads) : excPool(numThreads) {
        }

        ~BoostExecutor() override {
            this->excPool.join();
        }

        void task(std::function<void()> task) override {
            boost::asio::post(this->excPool,std::move(task));
        }
    private:
        boost::asio::thread_pool excPool;
    };
}

#endif //STREAM_V1_CORE_EXECUTOR_BOOSTEXECUTOR_HPP
