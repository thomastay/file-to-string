cmake_minimum_required (VERSION 3.0)
project (file2string)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wpedantic -g")

# add the executable
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.c)

add_custom_target(
    run 
    COMMAND ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    COMMENT "Running the Binary"
    )

#Time the binary
add_custom_target(
    time 
    COMMAND time ${CMAKE_BINARY_DIR}/${PROJECT_NAME} > /dev/null
    COMMENT "Timing the Binary"
    )