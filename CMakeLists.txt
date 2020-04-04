cmake_minimum_required(VERSION 3.15)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

# source files
set(cpp_source
        RPN.cpp)

foreach(source ${cpp_source})
    list(APPEND sources ${CMAKE_CURRENT_SOURCE_DIR}/src/${source})
endforeach()

add_library(algorithm SHARED ${sources})

# add test here
set(tests test_RPN)

foreach(test ${tests})
    add_executable(${test} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${test}.cpp)

    target_link_libraries(${test} algorithm)

endforeach()