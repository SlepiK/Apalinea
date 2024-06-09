//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_CORE_PLAN_HPP
#define STREAM_V1_CORE_PLAN_HPP

#include <memory>
#include <vector>
#include "Link/ILink.hpp"
#include "Link/PipeLink/PipeLink.hpp"
#include "Link/SinkLink/SinkLink.hpp"
#include "Link/SourceLink/SourceLink.hpp"

#include "Core/Executor/IExecutor.hpp"
#include "Core/Executor/BoostExecutor.hpp"

namespace Energyleaf::Stream::V1::Core::Plan {

    class Plan {
    public:
        Plan() : executor(std::make_shared<Executor::BoostExecutor>(3)) {
        }

        template<typename executor>
        Plan() : executor(std::make_shared<executor>()) {
        }

        explicit Plan(std::shared_ptr<Core::Executor::IExecutor> executor) : executor(std::move(executor)) {
        }

        virtual ~Plan() = default;

        template <typename PipeOperator>
        [[deprecated("Use createPipe() instead. Look for usage in the demo.")]]
        Link::PipeLinkPtr<PipeOperator> createLink(Link::PipeLinkUPtr<PipeOperator> link) {
            Link::PipeLinkPtr<PipeOperator> sharedLink = Link::PipeLinkPtr<PipeOperator>(std::move(link));
            vLinks.push_back(sharedLink);
            return sharedLink;
        }

        template <typename PipeOperator>
        Link::PipeLinkPtr<PipeOperator> createPipe() {
            Link::PipeLinkPtr<PipeOperator> pipe = this->createPipeLinkPtr<PipeOperator>();
            vLinks.push_back(pipe);
            return pipe;
        }

        template <typename SinkOperator>
        [[deprecated("Use createSink() instead. Look for usage in the demo.")]]
        Link::SinkLinkPtr<SinkOperator> createLink(Link::SinkLinkUPtr<SinkOperator> link) {
            Link::SinkLinkPtr<SinkOperator> sharedLink = Link::SinkLinkPtr<SinkOperator>(std::move(link));
            vLinks.push_back(sharedLink);
            return sharedLink;
        }

        template <typename SinkOperator>
        Link::SinkLinkPtr<SinkOperator> createSink() {
            Link::SinkLinkPtr<SinkOperator> sink = this->createSinkLinkPtr<SinkOperator>();
            vLinks.push_back(sink);
            vSinkLinks.push_back(sink);
            return sink;
        }

        template <typename SourceOperator>
        [[deprecated("Use createSource() instead. Look for usage in the demo.")]]
        Link::SourceLinkPtr<SourceOperator> createLink(Link::SourceLinkUPtr<SourceOperator> link) {
            Link::SourceLinkPtr<SourceOperator> sharedLink = Link::SourceLinkPtr<SourceOperator>(std::move(link));
            vLinks.push_back(sharedLink);
            vSourceLinks.push_back(sharedLink);
            return sharedLink;
        }

        template <typename SourceOperator>
        Link::SourceLinkPtr<SourceOperator> createSource() {
            Link::SourceLinkPtr<SourceOperator> source = this->createSourceLinkPtr<SourceOperator>();
            vLinks.push_back(source);
            vSourceLinks.push_back(source);
            return source;
        }

        template <typename T1, typename T2>
        void connect(Link::SourceLinkPtr<T1> source, Link::SinkLinkPtr<T2> target) {
            source->connect(target);
        }

        template <typename T1, typename T2>
        void connect(Link::SourceLinkPtr<T1> source, Link::PipeLinkPtr<T2> target) {
            source->connect(target);
        }

        /**
         * Allows to create inside of the plan a loop. So use on own risk and dont create a loop,
         * as this will result in undefined behaviour!
         * @tparam T1 PipeOperator
         * @tparam T2 PipeOperator
         * @param source PipeLink
         * @param target PipeLink
         */
        template <typename T1, typename T2>
        void connect(Link::PipeLinkPtr<T1> source, Link::PipeLinkPtr<T2> target) {
            source->connect(target);
        }

        template <typename T1, typename T2>
        void connect(Link::PipeLinkPtr<T1> source, Link::SinkLinkPtr<T2> target) {
            source->connect(target);
        }

        void process() {
            for(LinkIterator iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                (*iterator)->process();
            }
        }

        //Is checking if each registered Sink has processed
        bool isProcessed() {
            for(LinkIterator iterator = this->vSinkLinks.begin(); iterator != this->vSinkLinks.end(); ++iterator) {
                if(!(*iterator)->isProcessed()) {
                    return false;
                }
            }
            return true;
        }

        void join() {
            this->executor->joinTasks();
        }

        Core::Executor::IExecutor& getExecutor() {
            if(!executor) {
                throw std::runtime_error("Executor is not initialized");
            }
            return *this->executor;
        }

    private:
        std::vector<std::shared_ptr<Link::ILink>> vLinks;
        std::vector<std::shared_ptr<Link::ILink>> vSourceLinks;
        std::vector<std::shared_ptr<Link::ILink>> vSinkLinks;
        using LinkIterator = typename std::vector<std::shared_ptr<Link::ILink>>::iterator;
        std::shared_ptr<Core::Executor::IExecutor> executor;
    protected:
        template <typename SourceOperator>
        Link::SourceLinkPtr<SourceOperator> createSourceLinkPtr() {
            return std::make_shared<Link::SourceLink<SourceOperator>>(std::forward<SourceOperator>(SourceOperator()),this->executor);
        }

        template <typename SinkOperator>
        Link::SinkLinkPtr<SinkOperator> createSinkLinkPtr() {
            return std::make_shared<Link::SinkLink<SinkOperator>>(std::forward<SinkOperator>(SinkOperator()),this->executor);
        }

        template <typename PipeOperator>
        Link::PipeLinkPtr<PipeOperator> createPipeLinkPtr() {
            return std::make_shared<Link::PipeLink<PipeOperator>>(std::forward<PipeOperator>(PipeOperator()),this->executor);
        }
    };

} // Stream::V1::Core::Plan

#endif //STREAM_V1_CORE_PLAN_HPP
