cmake_minimum_required(VERSION 3.0.0)
project(openSnake)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set (openSnake_SRC
    handlers.cpp
    main.cpp
    snake.cpp
    sphere.cpp
    )

set(CMAKE_BUILD_DIR ${PROJECT_SOURCE_DIR}/build)

add_executable(${PROJECT_NAME} ${openSnake_SRC})
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARY}
    ${GLUT_LIBRARIES})
