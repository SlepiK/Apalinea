#ifndef APALINEA_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP
#define APALINEA_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP

#include "Core/Operator/PipeOperator/AbstractPipeOperator.hpp"
#include "Core/Tuple/Tuple.hpp"
#include "Core/Type/Datatype/DtBool.hpp"

namespace Apalinea::Operator::PipeOperator {
    class [[maybe_unused]] SelectPipeOperator
            : public Core::Operator::AbstractPipeOperator {
    protected:
        void work(Core::Tuple::Tuple &inputTuple,
                  Core::Tuple::Tuple &outputTuple) override {

            try {
                if (this->expression) {
                    this->expression->setTuple(inputTuple);
                    this->expression->execute();
                    if (Core::Type::Datatype::DtRegistry::get(this->expression->getIdentifier()) ==
                        Core::Type::Datatype::DtRegistry::get(Core::Type::Datatype::DtBool::IDENTIFIER)) {

                        bool eval = static_cast<const Core::Type::Datatype::DtBool&>(this->expression->getData()).toBool();

                        outputTuple.clear();
                        outputTuple.moveItems(std::move(inputTuple));
                        outputTuple.addItem(std::string("Select"),Core::Type::Datatype::DtBool(eval));
                        vProcessState = Core::Operator::OperatorProcessState::CONTINUE;
                    } else {
                        vProcessState = Core::Operator::OperatorProcessState::BREAK;
                    }
                } else {
                    throw std::runtime_error("No expression was used!");
                }
            } catch (const std::exception& e) {
                Core::Log::LogManager::log(Core::Log::LogLevelCategory::ERROR,Core::Log::getFilename(__FILE__),__LINE__,e.what());
                vProcessState = Core::Operator::OperatorProcessState::STOP;
            }
        }
    };
} // Apalinea::Operator::PipeOperator

#endif //APALINEA_OPERATOR_PIPEOPERATOR_SELECTPIPEOPERATOR_HPP
