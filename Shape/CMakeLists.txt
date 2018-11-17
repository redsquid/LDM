cmake_minimum_required(VERSION 3.1)

project(Shape)

include_directories(src)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")

set(SRC_DIR src)
set(TEST_SRC 
	${SRC_DIR}/Shape.cpp
)

file(GLOB SOURCES ${TEST_SRC})
add_library(ldmshape SHARED ${SOURCES})
