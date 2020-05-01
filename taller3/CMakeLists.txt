cmake_minimum_required(VERSION 3.3)
project(taller3)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(taller3 main.cpp)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(taller3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})