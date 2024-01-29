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
)

set(PROJECT_SOURCES
        main.cpp
        src/Operator/PipeOperator/AbstractPipeOperator.cpp
        src/Operator/SinkOperator/AbstractSinkOperator.cpp
        src/Operator/SourceOperator/AbstractSourceOperator.cpp
        src/Operator/AbstractOperator.cpp
        src/Core/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.cpp
        src/Tuple/Item/Item.cpp
        src/Tuple/Tuple.cpp
        src/Link/ILink.cpp
        src/Link/AbstractLink.cpp
        src/Link/PipeLink/PipeLink.cpp
        src/Link/SinkLink/SinkLink.cpp
        src/Link/SourceLink/SourceLink.cpp
        src/Core/Plan/Plan.cpp
)

add_executable(stream ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_include_directories(stream PRIVATE ${INCLUDE_DIRECTORYS})