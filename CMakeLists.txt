cmake_minimum_required(VERSION 3.27)
project(stream)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIRECTORYS
        include)

set(PROJECT_HEADERS
        include/Operator/Type/OperatorType.hpp
        include/Types/Datatype/DtRegistry.hpp
        include/Operator/PipeOperator/AbstractPipeOperator.hpp
        include/Operator/SinkOperator/AbstractSinkOperator.hpp
        include/Operator/SourceOperator/AbstractSourceOperator.hpp
        include/Operator/AbstractOperator.hpp
        include/Operator/IOperator.hpp
        include/Tuple/Entry/Entry.hpp
        include/Tuple/Tuple.hpp
        include/Core/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.hpp
        include/Link/ILink.hpp
        include/Link/AbstractLink.hpp
        include/Link/PipeLink/PipeLink.hpp
        include/Link/SinkLink/SinkLink.hpp
        include/Link/SourceLink/SourceLink.hpp
        include/Link/Trait/LinkTrait.hpp
        include/Link/Wrapper/LinkWrapper.hpp
        include/Core/Plan/Plan.hpp
        include/Core/Operator/SourceOperator/StringDemoSourceOperator/StringDemoSourceOperator.hpp
        include/Core/Constants/Version.hpp
        include/Core/Operator/PipeOperator/CalculatorPipeOperator/CalculatorPipeOperator.hpp
        include/Types/Power/Power.hpp
        include/Types/Image/Image.hpp
        include/Types/Image/ImageFormat.hpp
        include/Core/Operator/PipeOperator/CropPipeOperator/CropPipeOperator.hpp
        include/Types/Pixel/HSV.hpp
        include/Types/Pixel/RGB.hpp
        include/Extras/Converter/Types/Pixel/RGBtoHSV.hpp
        include/Core/Operator/PipeOperator/StatePipeOperator/StatePipeOperator.hpp
        include/Core/Operator/PipeOperator/WindowPipeOperator/WindowPipeOperator.hpp
        include/Core/Operator/PipeOperator/SelectPipeOperator/SelectPipeOperator.hpp
        include/Core/Operator/PipeOperator/DetectorPipeOperator/DetectorPipeOperator.hpp
        include/Extras/Vision/Camera/AbstractCamera.hpp
        include/Types/Window/WindowId.hpp
        include/Core/Operator/SourceOperator/CameraSourceOperator/CameraSourceOperator.hpp
        include/Core/Operator/SourceOperator/CameraSourceOperator/CameraSourceOperatorTrait.hpp
        include/Operator/ProcessState/OperatorProcessState.hpp
        include/Types/Datatype/IDtTrait.hpp
        include/Expression/IExpression.hpp
        include/Expression/Expression.hpp
        include/Expression/ToExpression/ToDtStringExpression.hpp
        include/Types/Datatype/DtString.hpp
        include/Types/Datatype/DtInt32.hpp
        include/Types/Datatype/DtInt8.hpp
        include/Types/Datatype/DtInt16.hpp
        include/Types/Datatype/DtUInt8.hpp
        include/Types/Datatype/DtUInt16.hpp
        include/Types/Datatype/DtUInt32.hpp
        include/Types/Datatype/DtInt64.hpp
        include/Types/Datatype/DtUInt64.hpp
        include/Types/Datatype/DtInt.hpp
        include/Types/Datatype/DtSizeT.hpp
        include/Exception/NotImplementedException.hpp
        include/Types/Datatype/IDt.hpp
        include/Expression/Datatype/DtIntExpression.hpp
        include/Expression/Datatype/DtInt16Expression.hpp
        include/Expression/Datatype/DtInt32Expression.hpp
        include/Expression/Datatype/DtInt64Expression.hpp
        include/Expression/Datatype/DtInt8Expression.hpp
        include/Expression/Datatype/DtSizeTExpression.hpp
        include/Expression/Datatype/DtStringExpression.hpp
        include/Expression/Datatype/DtUInt8Expression.hpp
        include/Expression/Datatype/DtUInt16Expression.hpp
        include/Expression/Datatype/DtUInt32Expression.hpp
        include/Expression/Datatype/DtUInt64Expression.hpp
        include/Expression/ToExpression/ToDtIntExpression.hpp
        include/Expression/IExpressionUnit.hpp
        include/Expression/Compare/CompareExpression.hpp
        include/Types/Datatype/DtBool.hpp
        include/Expression/Datatype/DtBoolExpression.hpp
        include/Expression/Calculation/CalculationExpression.hpp
        include/Types/Datatype/DtNumbers.hpp
        include/Types/Datatype/DtRegistry.cpp
        include/Types/Datatype/DtFloat.hpp
        include/Types/Datatype/DtDouble.hpp
)

set(PROJECT_SOURCES
        include/Types/Datatype/DtUInt64.cpp
        include/Types/Datatype/DtInt64.cpp
        include/Types/Datatype/DtInt8.cpp
        include/Types/Datatype/DtInt16.cpp
        include/Types/Datatype/DtInt32.cpp
        include/Types/Datatype/DtSizeT.cpp
        include/Types/Datatype/DtUInt8.cpp
        include/Types/Datatype/DtUInt16.cpp
        include/Types/Datatype/DtUInt32.cpp
        include/Types/Datatype/DtInt.cpp
        include/Types/Datatype/DtBool.cpp
        include/Types/Datatype/DtFloat.cpp
        include/Types/Datatype/DtDouble.cpp
)

set(DEMO_SOURCES
        example/example.cpp
)

add_executable(stream main.cpp ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_include_directories(stream PRIVATE ${INCLUDE_DIRECTORYS})
add_executable(example ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${DEMO_SOURCES})
target_include_directories(example PRIVATE ${INCLUDE_DIRECTORYS})