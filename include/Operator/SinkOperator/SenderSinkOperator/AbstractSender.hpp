#ifndef APALINEA_OPERATOR_SINKOPERATOR_ABSTRACTSENDER_HPP
#define APALINEA_OPERATOR_SINKOPERATOR_ABSTRACTSENDER_HPP

#include "Core/Operator/SinkOperator/AbstractSinkOperator.hpp"

namespace Apalinea::Operator::SinkOperator {
    class AbstractSender {
    public:
        AbstractSender() = default;
        ~AbstractSender() = default;
        virtual bool work(Core::Tuple::Tuple &inputTuple) = 0;
    private:
    protected:
    };
} // Apalinea::Operator::SinkOperator

#endif //APALINEA_OPERATOR_SINKOPERATOR_ABSTRACTSENDER_HPP
