//
// Created by Simon Stahmer on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP

#include <Operator/SinkOperator/AbstractSinkOperator.hpp>
#include <ostream>
#include <Tuple/Tuple.hpp>

#include <Expression/ToExpression/ToStringExpression.hpp>
#include <Expression/ExpressionUnit.hpp>

namespace Energyleaf::Stream::V1::Core::Operator::SinkOperator {
    template<typename Writer>
    class WriteSinkOperator
            : public Energyleaf::Stream::V1::Operator::AbstractSinkOperator{
    public:
        explicit WriteSinkOperator() : vWriter() {
        }

        WriteSinkOperator(WriteSinkOperator&& other) noexcept
                : vWriter(std::move(other.vWriter)) {
        }

        WriteSinkOperator(WriteSinkOperator& other) noexcept
                : vWriter(other.vWriter) {
        }

        ~WriteSinkOperator() override = default;

        Writer& getWriter() {
            return this->vWriter;
        }
    private:
        Writer vWriter;
    protected:
        void work(Tuple::Tuple &inputTuple) override {
            try {
                Expression::ToStringExpression* tse = new Expression::ToStringExpression();
                Expression::ExpressionUnit* eu = new Expression::ExpressionUnit("DemoString");
                eu->setTuple(inputTuple);
                tse->add(eu);
                tse->execute();
                vWriter << tse->getString() << std::endl;
                tse->remove(eu);
                delete eu;
                delete tse; //Demo Code of a real basic expression to get or convert an unit to string.
                //vWriter << inputTuple.getItem<Types::Base::StringItem>("DemoString").toString() << std::endl;
                //vWriter << inputTuple.getEntry("DemoString").get<Types::Base::StringItem>().toString() << std::endl;
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::CONTINUE;
            } catch (std::exception& e) {
                vProcessState = Energyleaf::Stream::V1::Operator::OperatorProcessState::STOP;
            }
        }
    };
}

#endif
