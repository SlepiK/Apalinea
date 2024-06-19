#ifndef APALINEA_OPERATOR_SINKOPERATORCONSOLEWRITER_HPP
#define APALINEA_OPERATOR_SINKOPERATORCONSOLEWRITER_HPP

#include <iostream>
#include "Operator/SinkOperator/WriteSinkOperator/AbstractWriter.hpp"

namespace Apalinea::Operator::SinkOperator {
    class ConsoleWriter : public AbstractWriter {
    protected:
        void write(const std::string& message) override {
            std::cout << message;
        }

        void breakAndFlush() override {
            std::cout << std::endl;
        }
    };
} // Apalinea::Operator::SinkOperator

#endif //APALINEA_OPERATOR_SINKOPERATORCONSOLEWRITER_HPP
