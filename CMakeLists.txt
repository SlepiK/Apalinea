cmake_minimum_required(VERSION 3.27)
project(stream)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIRECTORYS
        include)

option(USE_BOOST "Use Boost Libraries" OFF)

if(USE_BOOST)
    set(BOOST_REQUIRED_COMPONENTS
        filesystem
        thread
    )

    set(BOOST_MIN_VERSION 1.70.0)

    # Find Boost
    find_package(Boost ${BOOST_MIN_VERSION} REQUIRED COMPONENTS ${BOOST_REQUIRED_COMPONENTS})

    #Include Boost
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(PROJECT_HEADERS
        include/Core/Operator/Type/OperatorType.hpp
        include/Core/Type/Datatype/DtRegistry.hpp
        include/Core/Operator/PipeOperator/AbstractPipeOperator.hpp
        include/Core/Operator/SinkOperator/AbstractSinkOperator.hpp
        include/Core/Operator/SourceOperator/AbstractSourceOperator.hpp
        include/Core/Operator/AbstractOperator.hpp
        include/Core/Operator/IOperator.hpp
        include/Core/Tuple/Entry/Entry.hpp
        include/Core/Tuple/Tuple.hpp
        include/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.hpp
        include/Core/Link/ILink.hpp
        include/Core/Link/AbstractLink.hpp
        include/Core/Link/PipeLink/PipeLink.hpp
        include/Core/Link/SinkLink/SinkLink.hpp
        include/Core/Link/SourceLink/SourceLink.hpp
        include/Core/Link/Trait/LinkTrait.hpp
        include/Core/Link/Wrapper/LinkWrapper.hpp
        include/Core/Plan/Plan.hpp
        include/Operator/SourceOperator/StringDemoSourceOperator/StringDemoSourceOperator.hpp
        include/Core/Constants/Version.hpp
        include/Operator/PipeOperator/CalculatorPipeOperator/CalculatorPipeOperator.hpp
        include/Core/Type/Power/Power.hpp
        include/Core/Type/Image/Image.hpp
        include/Core/Type/Image/ImageFormat.hpp
        include/Operator/PipeOperator/CropPipeOperator/CropPipeOperator.hpp
        include/Core/Type/Pixel/HSV.hpp
        include/Core/Type/Pixel/RGB.hpp
        include/Extras/Converter/Types/Pixel/RGBtoHSV.hpp
        include/Operator/PipeOperator/StatePipeOperator/StatePipeOperator.hpp
        include/Operator/PipeOperator/WindowPipeOperator/WindowPipeOperator.hpp
        include/Operator/PipeOperator/SelectPipeOperator/SelectPipeOperator.hpp
        include/Operator/PipeOperator/DetectorPipeOperator/DetectorPipeOperator.hpp
        include/Extras/Vision/Camera/AbstractCamera.hpp
        include/Core/Type/Window/WindowId.hpp
        include/Operator/SourceOperator/CameraSourceOperator/CameraSourceOperator.hpp
        include/Operator/SourceOperator/CameraSourceOperator/CameraSourceOperatorTrait.hpp
        include/Core/Operator/ProcessState/OperatorProcessState.hpp
        include/Core/Tuple/Trait/TupleTrait.hpp
        include/Expression/IExpression.hpp
        include/Expression/AbstractExpression.hpp
        include/Expression/ToExpression/ToDtStringExpression.hpp
        include/Core/Type/Datatype/DtString.hpp
        include/Core/Type/Datatype/DtInt32.hpp
        include/Core/Type/Datatype/DtInt8.hpp
        include/Core/Type/Datatype/DtInt16.hpp
        include/Core/Type/Datatype/DtUInt8.hpp
        include/Core/Type/Datatype/DtUInt16.hpp
        include/Core/Type/Datatype/DtUInt32.hpp
        include/Core/Type/Datatype/DtInt64.hpp
        include/Core/Type/Datatype/DtUInt64.hpp
        include/Core/Type/Datatype/DtInt.hpp
        include/Core/Type/Datatype/DtSizeT.hpp
        include/Core/Exception/NotImplementedException.hpp
        include/Core/Type/Datatype/IDt.hpp
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
        include/Core/Type/Datatype/DtBool.hpp
        include/Expression/Datatype/DtBoolExpression.hpp
        include/Expression/Calculation/CalculationExpression.hpp
        include/Core/Type/Datatype/DtNumbers.hpp
        include/Core/Type/Datatype/DtFloat.hpp
        include/Core/Type/Datatype/DtDouble.hpp
        include/Expression/Datatype/DtFloatExpression.hpp
        include/Expression/Datatype/DtDoubleExpression.hpp
        include/Expression/ToExpression/ToDtFloatExpression.hpp
        include/Expression/ToExpression/ToDtDoubleExpression.hpp
        include/Expression/ToExpression/ToDtBoolExpression.hpp
        include/Core/Type/Datatype/DtImage.hpp
        include/Core/Executor/IExecutor.hpp
        include/Core/Executor/BoostExecutor.hpp
        include/Core/Operator/Type/OperatorMode.hpp
        include/Core/Executor/STLExecutor.hpp
        include/Core/Link/Type/LinkType.hpp
        include/Core/Link/IBaseLink.hpp
        include/Core/Log/ILog.hpp
        include/Core/Log/LogLevelCategory.hpp
        include/Core/Log/ConsoleLog.hpp
        include/Core/Log/LogManager.hpp
)

set(PROJECT_SOURCES
        src/Core/Constants/Settings.cpp
        src/Core/Type/Datatype/DtUInt64.cpp
        src/Core/Type/Datatype/DtInt64.cpp
        src/Core/Type/Datatype/DtInt8.cpp
        src/Core/Type/Datatype/DtInt16.cpp
        src/Core/Type/Datatype/DtInt32.cpp
        src/Core/Type/Datatype/DtSizeT.cpp
        src/Core/Type/Datatype/DtUInt8.cpp
        src/Core/Type/Datatype/DtUInt16.cpp
        src/Core/Type/Datatype/DtUInt32.cpp
        src/Core/Type/Datatype/DtInt.cpp
        src/Core/Type/Datatype/DtBool.cpp
        src/Core/Type/Datatype/DtFloat.cpp
        src/Core/Type/Datatype/DtDouble.cpp
        src/Core/Type/Datatype/DtImage.cpp
        src/Core/Type/Datatype/DtRegistry.cpp
        src/Core/Log/LogManager.cpp
)

set(DEMO_SOURCES
        example/example.cpp
        include/Core/Log/LogLevel.hpp
)

add_executable(stream main.cpp ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_include_directories(stream PRIVATE ${INCLUDE_DIRECTORYS})
if(USE_BOOST)
target_link_libraries(stream ${Boost_LIBRARIES})
endif()

add_executable(example ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${DEMO_SOURCES})
target_include_directories(example PRIVATE ${INCLUDE_DIRECTORYS})
if(USE_BOOST)
target_link_libraries(example ${Boost_LIBRARIES})
endif()