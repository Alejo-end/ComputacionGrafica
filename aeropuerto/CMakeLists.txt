cmake_minimum_required(VERSION 3.3)
project(aeropuerto)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(aeropuerto main.cpp)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(aeropuerto ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})