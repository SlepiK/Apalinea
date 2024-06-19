//
// Created by SlepiK on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERATORCONSOLEWRITER_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERATORCONSOLEWRITER_HPP

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
}

#endif //STREAM_V1_CORE_OPERATOR_SINKOPERATORCONSOLEWRITER_HPP
