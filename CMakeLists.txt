cmake_minimum_required(VERSION 3.0.0)
project(openSnake)

set (openSnake_VERSION_MAJOR 0)
set (openSnake_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(
    "${PROJECT_SOURCE_DIR}/openSnakeConfig.h.in"
    "${PROJECT_SOURCE_DIR}/openSnakeConfig.h"
    )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    #Force -Wall to catch every little warning
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

    if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    endif()

endif()

set (openSnake_SRC
    handlers.cpp
    main.cpp
    snake.cpp
    sphere.cpp
    helper_functions.cpp
    )

set(CMAKE_BUILD_DIR ${PROJECT_SOURCE_DIR}/build)

add_executable(${PROJECT_NAME} ${openSnake_SRC})
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARY}
    ${GLUT_LIBRARIES}
    ${GLEW_LIBRARIES}
    )
