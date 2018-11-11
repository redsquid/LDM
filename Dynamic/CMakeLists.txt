cmake_minimum_required(VERSION 3.1)

project(Dynamic)

find_library(GSL_LIBRARY gsl)
find_library(GSLCBLAS_LIBRARY gslcblas)

#find_library(PCRE_LIBRARY pcre)

include_directories(src ../lib/ldmtest/include)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -finline-functions -ffast-math -fstrength-reduce")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")



#For the shared library:
set ( LIBLDMTEST libldmtest.so )
link_directories( ../lib/ldmtest )
#include_directories(../lib/ldmtest/include)
 
set(SRC_DIR src)
set(LDM_SRC 
	${SRC_DIR}/main.cpp

	${SRC_DIR}/main.cpp
	${SRC_DIR}/data/Data.cpp
	${SRC_DIR}/nucleus/Nucleus.cpp
	${SRC_DIR}/reaction/Reaction.cpp
	${SRC_DIR}/random/Random.cpp
	${SRC_DIR}/mass/Mass.cpp
	${SRC_DIR}/friction/Friction.cpp
	${SRC_DIR}/potential/Potential.cpp
	${SRC_DIR}/potential/PotentialLoader.cpp
)



add_executable(main ${LDM_SRC})

target_link_libraries(main ${GSL_LIBRARY} ${GSLCBLAS_LIBRARY} ${LIBLDMTEST})
