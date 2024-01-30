cmake_minimum_required(VERSION 3.27)
project(stream)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIRECTORYS
        include)

set(PROJECT_HEADERS
        include/Operator/Type/OperatorType.hpp
        include/Operator/PipeOperator/AbstractPipeOperator.hpp
        include/Operator/SinkOperator/AbstractSinkOperator.hpp
        include/Operator/SourceOperator/AbstractSourceOperator.hpp
        include/Operator/AbstractOperator.hpp
        include/Operator/IOperator.hpp
        include/Tuple/Item/Item.hpp
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
        include/Types/Empty/EmptyType.hpp
        include/Core/Operator/SinkOperator/SerialSinkOperator/SerialSinkOperator.hpp
        include/Types/Power/Power.hpp
        include/Types/Image/Image.hpp
        include/Types/Image/ImageFormat.hpp
        include/Core/Operator/PipeOperator/CropPipeOperator/CropPipeOperator.hpp
        include/Types/Pixel/HSV.hpp
        include/Types/Pixel/RGB.hpp
        include/Extras/Converter/Types/Pixel/RGBtoHSV.hpp
        include/Extras/Network/ESP/WebSender/WebSender.hpp
        include/Core/Operator/SinkOperator/WebSenderSinkOperator/WebSenderSinkOperator.hpp
        include/Core/Operator/PipeOperator/StatePipeOperator/StatePipeOperator.hpp
        include/Core/Operator/PipeOperator/WindowPipeOperator/WindowPipeOperator.hpp
        include/Core/Operator/PipeOperator/SelectPipeOperator/SelectPipeOperator.hpp
)

set(PROJECT_SOURCES
        src/Operator/AbstractOperator.cpp
        src/Link/AbstractLink.cpp
)

set(DEMO_SOURCES
        example/example.cpp
)

add_executable(stream main.cpp ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_include_directories(stream PRIVATE ${INCLUDE_DIRECTORYS})
add_executable(example ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${DEMO_SOURCES})
target_include_directories(example PRIVATE ${INCLUDE_DIRECTORYS})