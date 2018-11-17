cmake_minimum_required(VERSION 3.1)

project(Mass)

find_library(GSL_LIBRARY gsl)
find_library(GSLCBLAS_LIBRARY gslcblas)

include_directories(
	src
	../lib/ldmtest/include
	../lib/ldmshape/include
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -finline-functions -ffast-math -fstrength-reduce")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")

set(LIBLDMTEST libldmtest.so)
link_directories(../lib/ldmtest)
set(LIBLDMSHAPE libldmshape.so)
link_directories(../lib/ldmshape)

set(SRC_DIR src)
set(LDM_SRC 
	${SRC_DIR}/main.cpp
	${SRC_DIR}/mass/A.cpp
	${SRC_DIR}/mass/Mass.cpp
	${SRC_DIR}/gauss/GaussTable.cpp
)

add_executable(main ${LDM_SRC})

target_link_libraries(main ${GSL_LIBRARY} ${GSLCBLAS_LIBRARY} ${LIBLDMTEST} ${LIBLDMSHAPE})

