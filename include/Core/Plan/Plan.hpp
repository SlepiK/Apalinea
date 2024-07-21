#ifndef APALINEA_CORE_PLAN_PLAN_HPP
#define APALINEA_CORE_PLAN_PLAN_HPP

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
        [[maybe_unused]] Link::PipeLinkPtr<PipeOperator> createPipe() {
            Link::PipeLinkPtr<PipeOperator> pipe = this->createPipeLinkPtr<PipeOperator>();
            Log::LogManager::log(Log::LogLevelCategory::INFORMATION,Log::getFilename(__FILE__),__LINE__,"Creating new PipeLink");
            vLinks.push_back(pipe);
            vPipeLinks.push_back(pipe);
            return pipe;
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
        [[maybe_unused]]void connect(Link::SourceLinkPtr<T1> source, Link::PipeLinkPtr<T2> target) {
            source->connect(target);
        }

        template <typename T1, typename T2>
        [[maybe_unused]] void connect(Link::PipeLinkPtr<T1> source, Link::PipeLinkPtr<T2> target) {
            source->connect(target);
        }

        template <typename T1, typename T2>
        [[maybe_unused]] void connect(Link::PipeLinkPtr<T1> source, Link::SinkLinkPtr<T2> target) {
            source->connect(target);
        }

        void process() {
            for(auto & vLink : this->vLinks) {
                vLink->process();
            }
        }

        [[maybe_unused]] bool isProcessed() {
            for(auto & vSinkLink : this->vSinkLinks) {
                if(!vSinkLink->isProcessed()) {
                    return false;
                }
            }
            return true;
        }

        void join() {
            this->executor->joinTasks();
        }

        [[maybe_unused]] Core::Executor::IExecutor& getExecutor() {
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
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR,Core::Log::getFilename(__FILE__),__LINE__,"Links already ordered");
                throw std::runtime_error("Links already ordered!");
            }
        }

        void processOrdered() {
            if(vOrderedLinks.empty()) throw std::runtime_error("Need ordered plan to run!");
            for(auto & vOrderedLink : this->vOrderedLinks) {
                vOrderedLink->process();
            }
        }

    private:
        std::vector<std::shared_ptr<Link::ILink>> vLinks;
        std::vector<std::shared_ptr<Link::ILink>> vSourceLinks;
        std::vector<std::shared_ptr<Link::ILink>> vPipeLinks;
        std::vector<std::shared_ptr<Link::ILink>> vSinkLinks;
        using LinkIterator [[maybe_unused]] = typename std::vector<std::shared_ptr<Link::ILink>>::iterator;
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
                            auto* tmp = static_cast<Link::IBaseLink*>(connectedLink.get());
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
} // Apalinea::Core::Plan

#endif //APALINEA_CORE_PLAN_PLAN_HPP
