//
// Created by SlepiK on 28.01.2024.
//

#ifndef STREAM_V1_CORE_PLAN_HPP
#define STREAM_V1_CORE_PLAN_HPP

#include <memory>
#include <vector>
#include <queue>
#include "Core/Executor/IExecutor.hpp"
#include "Core/Log/LogManager.hpp"
#include "Core/Link/ILink.hpp"
#include "Core/Link/PipeLink/PipeLink.hpp"
#include "Core/Link/SinkLink/SinkLink.hpp"
#include "Core/Link/SourceLink/SourceLink.hpp"

namespace Apalinea::Core::Plan {

    class Plan {
    public:

        template<typename executor>
        Plan() : executor(std::make_shared<executor>()) {
            if(!Log::LogManager::haveLog()) throw std::runtime_error("No Log was registered!");
        }

        explicit Plan(std::shared_ptr<Core::Executor::IExecutor> executor) : executor(std::move(executor)) {
            if(!Log::LogManager::haveLog()) throw std::runtime_error("No Log was registered!");
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
            Log::LogManager::log(Log::LogLevelCategory::INFORMATION,Log::getFilename(__FILE__),__LINE__,"Creating new PipeLink");
            vLinks.push_back(pipe);
            vPipeLinks.push_back(pipe);
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
            Log::LogManager::log(Log::LogLevelCategory::INFORMATION,Log::getFilename(__FILE__),__LINE__,"Creating new SinkLink");
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
            Log::LogManager::log(Log::LogLevelCategory::INFORMATION,Log::getFilename(__FILE__),__LINE__,"Creating new SourceLink");
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

        void order() {
            if(vOrderedLinks.empty()) {
                vOrderedLinks = vSourceLinks;
                std::vector<std::shared_ptr<Link::ILink>> last = vSourceLinks;
                batchOrdering(last);
            } else {
                throw std::runtime_error("Links already ordered!");
            }
        }

        void processOrdered() {
            if(vOrderedLinks.empty()) throw std::runtime_error("Need ordered plan to run!");
            for(LinkIterator iterator = this->vOrderedLinks.begin(); iterator != this->vOrderedLinks.end(); ++iterator) {
                (*iterator)->process();
            }
        }

    private:
        std::vector<std::shared_ptr<Link::ILink>> vLinks;
        std::vector<std::shared_ptr<Link::ILink>> vSourceLinks;
        std::vector<std::shared_ptr<Link::ILink>> vPipeLinks;
        std::vector<std::shared_ptr<Link::ILink>> vSinkLinks;
        using LinkIterator = typename std::vector<std::shared_ptr<Link::ILink>>::iterator;
        std::shared_ptr<Core::Executor::IExecutor> executor;
        std::vector<std::shared_ptr<Link::ILink>> vOrderedLinks;
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

        bool batchOrdering(std::vector<std::shared_ptr<Link::ILink>>& last) {
            if (!last.empty()) {
                std::queue<std::shared_ptr<Link::ILink>> queueLast;
                for (auto& link : last) {
                    queueLast.push(link);
                }
                while (!queueLast.empty()) {
                    auto currentLink = queueLast.front();
                    queueLast.pop();

                    std::optional<std::reference_wrapper<const std::vector<std::shared_ptr<Link::LinkWrapper>>>> connectedLinks = currentLink->getLinks();
                    if (connectedLinks.has_value()) {
                        for (const auto& connectedLink : connectedLinks.value().get()) {
                            Link::IBaseLink* tmp = static_cast<Link::IBaseLink*>(connectedLink.get());
                            for (auto& vLink : this->vLinks) {
                                if (vLink->getType() == Link::LinkType::SOURCE)
                                    continue;
                                if (tmp == static_cast<Link::IBaseLink*>(vLink.get())) {
                                    if (std::find(vOrderedLinks.begin(), vOrderedLinks.end(), vLink) == vOrderedLinks.end()) {
                                        vOrderedLinks.push_back(vLink);
                                        queueLast.push(vLink);
                                    }
                                }
                            }
                        }
                    }
                }
                return true;
            } else {
                return false;
            }
        }

    };

} // Stream::V1::Core::Plan

#endif //STREAM_V1_CORE_PLAN_HPP
