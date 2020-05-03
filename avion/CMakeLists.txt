
cmake_minimum_required(VERSION 3.3)
project(avion)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(avion main.cpp helicopter.cpp)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(avion ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})