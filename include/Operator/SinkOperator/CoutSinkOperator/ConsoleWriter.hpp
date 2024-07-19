#ifndef APALINEA_OPERATOR_SINKOPERATORCONSOLEWRITER_HPP
#define APALINEA_OPERATOR_SINKOPERATORCONSOLEWRITER_HPP

#include <iostream>
#include "Operator/SinkOperator/WriteSinkOperator/AbstractWriter.hpp"
#include "Core/Log/LogManager.hpp"

namespace Apalinea::Operator::SinkOperator {
    class ConsoleWriter : public AbstractWriter {
    protected:
        void write(const std::string& message) override {
            Core::Log::LogManager::log(Core::Log::LogLevelCategory::INFORMATION,Core::Log::getFilename(__FILE__),__LINE__,message);
        }

        void breakAndFlush() override {}
    };
} // Apalinea::Operator::SinkOperator

#endif //APALINEA_OPERATOR_SINKOPERATORCONSOLEWRITER_HPP
