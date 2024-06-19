#ifndef APALINEA_CORE_LINK_SOURCELINK_HPP
#define APALINEA_CORE_LINK_SOURCELINK_HPP

#include <utility>
#include <vector>
#include "Core/Link/AbstractLink.hpp"
#include "Core/Link/PipeLink/PipeLink.hpp"
#include "Core/Link/SinkLink/SinkLink.hpp"
#include "Core/Link/SourceLink/SourceLink.hpp"

namespace Apalinea::Core::Link {
    template<typename SourceOperator>
    class SourceLink : public AbstractLink {
        static_assert(IsBasedOnAbstractSourceOperator<SourceOperator>::value,"SourceOperator must be based on AbstractSourceOperator!");
    public:
        explicit SourceLink(SourceOperator&& sourceOperator, std::shared_ptr<Core::Executor::IExecutor> executor) :
            AbstractLink(executor),
            vOperator(std::forward<SourceOperator>(sourceOperator)) {
        }

        explicit SourceLink(SourceOperator& sourceOperator, std::shared_ptr<Core::Executor::IExecutor> executor) :
            AbstractLink(executor),
            vOperator(std::move(sourceOperator)) {
        }

        SourceLink(SourceLink &&other) noexcept
                : vOperator(std::move(other.vOperator)) {
        }

        ~SourceLink() override = default;

        [[maybe_unused]] SourceOperator& getOperator() {
            return this->vOperator;
        }

        void process() override {
            if(this->vOperator.getOperatorMode() == Core::Operator::OperatorMode::TASK) {
                this->executor.get()->addTask([this] { this->exec(); });
            } else {
                this->exec();
            }
        }

        template<typename PipeOperator>
        void connect(const PipeLinkPtr<PipeOperator> &nextLink) {
            this->vLinks.push_back(nextLink);
        }

        template<typename SinkOperator>
        void connect(const SinkLinkPtr<SinkOperator> &nextLink) {
            this->vLinks.push_back(nextLink);
        }

        std::optional<std::reference_wrapper<const std::vector<std::shared_ptr<LinkWrapper>>>> getLinks() override {
            return std::cref(this->vLinks);
        }

        [[nodiscard]] LinkType getType() const override {
            return LinkType::SOURCE;
        }

    private:
        SourceOperator vOperator;
        std::vector<std::shared_ptr<LinkWrapper>> vLinks;
        using LinkIterator [[maybe_unused]] = typename std::vector<std::shared_ptr<LinkWrapper>>::iterator;

    protected:
        void exec() {
            if (this->vProcessing) throw std::runtime_error("(Source-)Link is already processing!");
            if (this->vProcessed) this->vProcessed = false;
            if (!this->vProcessing) this->vProcessing = true;

            if(this->vState == Core::Operator::OperatorProcessState::CONTINUE || this->vState == Core::Operator::OperatorProcessState::BREAK) {
                Tuple::Tuple outputTuple;
                this->vOperator.process(outputTuple);
                this->vState = this->vOperator.getOperatorProcessState();

                for (auto iterator = this->vLinks.begin(); iterator != this->vLinks.end(); ++iterator) {
                    if (this->vState == Core::Operator::OperatorProcessState::CONTINUE) {
                        (*iterator)->setInputTuple(outputTuple);
                        (*iterator)->setOperatorProcessState(this->vState);
                    } else {
                        (*iterator)->setOperatorProcessState(this->vState);
                    }
                }

                outputTuple.clear();
            }

            this->vProcessing = false;
            this->vProcessed = true;
        }
    };

    template<typename SourceOperator>
    using SourceLinkPtr = std::shared_ptr<SourceLink<SourceOperator>>;
    template<typename SourceOperator>
    using SourceLinkUPtr [[maybe_unused]] = std::unique_ptr<SourceLink<SourceOperator>>;
} // Apalinea::Core::Link

#endif //APALINEA_CORE_LINK_SOURCELINK_HPP
