cmake_minimum_required(VERSION 3.27)
project(stream)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIRECTORYS
        include)

set(PROJECT_HEADERS
        include/Operator/Type/OperatorType.hpp
        include/Operator/PipeOperator/PipeOperator.hpp
        include/Operator/SinkOperator/SinkOperator.hpp
        include/Operator/SourceOperator/SourceOperator.hpp
        include/Operator/AbstractOperator.hpp
        include/Operator/IOperator.hpp
        include/Tuple/Item/Item.hpp
        include/Tuple/Tuple.hpp
        include/Core/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.hpp
        )

set(PROJECT_SOURCES
        main.cpp
        src/Operator/PipeOperator/PipeOperator.cpp
        src/Operator/SinkOperator/SinkOperator.cpp
        src/Operator/SourceOperator/SourceOperator.cpp
        src/Operator/AbstractOperator.cpp
        src/Core/Operator/SinkOperator/CoutSinkOperator/CoutSinkOperator.cpp
        src/Tuple/Item/Item.cpp
        src/Tuple/Tuple.cpp
)

add_executable(stream ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_include_directories(stream PRIVATE ${INCLUDE_DIRECTORYS})