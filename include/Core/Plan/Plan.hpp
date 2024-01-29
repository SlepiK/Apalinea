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

namespace Stream::V1::Core::Plan {

    class Plan {
    public:
        Plan() = default;
        virtual ~Plan() = default;

        template <typename PipeOperator>
        Link::PipeLinkPtr<PipeOperator> createLink(Link::PipeLinkUPtr<PipeOperator> link) {
            Link::PipeLinkPtr<PipeOperator> sharedLink = Link::PipeLinkPtr<PipeOperator>(std::move(link));
            vLinks.push_back(sharedLink);
            return sharedLink;
        }

        template <typename SinkOperator>
        Link::SinkLinkPtr<SinkOperator> createLink(Link::SinkLinkUPtr<SinkOperator> link) {
            Link::SinkLinkPtr<SinkOperator> sharedLink = Link::SinkLinkPtr<SinkOperator>(std::move(link));
            vLinks.push_back(sharedLink);
            return sharedLink;
        }

        template <typename SourceOperator>
        Link::SourceLinkPtr<SourceOperator> createLink(Link::SourceLinkUPtr<SourceOperator> link) {
            Link::SourceLinkPtr<SourceOperator> sharedLink = Link::SourceLinkPtr<SourceOperator>(std::move(link));
            vLinks.push_back(sharedLink);
            return sharedLink;
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
    private:
        std::vector<std::shared_ptr<Link::ILink>> vLinks;
        using LinkIterator = std::vector<std::shared_ptr<Link::ILink>>::iterator;
    protected:
    };

} // Stream::V1::Core::Plan

#endif //STREAM_V1_CORE_PLAN_HPP
