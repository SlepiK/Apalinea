//
// Created by Simon Stahmer on 13.02.24.
//

#ifndef STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP
#define STREAM_V1_CORE_OPERATOR_SINKOPERAOTR_WRITESINKOPERATOR_HPP

#include <Operator/SinkOperator/AbstractSinkOperator.hpp>
#include <ostream>
#include <Tuple/Tuple.hpp>

#include <Expression/ToExpression/ToDtStringExpression.hpp>
#include <Expression/Datatype/DtInt8Expression.hpp>
#include <Types/Datatype/DtRegistry.hpp>

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
                Expression::ToDtStringExpression tse = Expression::ToDtStringExpression();
                Expression::DataType::DtInt8Expression *edt = new Expression::DataType::DtInt8Expression("DemoString");
                edt->setTuple(inputTuple);
                tse.add(edt);
                tse.execute();
                if(Types::Datatype::DtRegistry::get(tse.getIdentifier()) == Types::Datatype::DtRegistry::get(Types::Datatype::DtString::IDENTIFIER)) {
                    vWriter << static_cast<const Types::Datatype::DtString&>(tse.getData()).toString() << std::endl;
                }
                tse.remove(edt);
                delete edt;


                /*Expression::ToDtStringExpression* tse = new Expression::ToDtStringExpression();
                Expression::ExpressionUnit* eu = new Expression::ExpressionUnit(std::vector<std::string_view>(),
                                                                                "DemoString");
                eu->setTuple(inputTuple);
                tse->add(eu);
                tse->execute();
                vWriter << tse->getString() << std::endl;
                tse->remove(eu);
                delete eu;
                delete tse;*/ //Demo Code of a real basic expression to get or convert an unit to string.
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
