cmake_minimum_required(VERSION 3.1)

# так пишутся комментарии

project(example)

find_library(GSL_LIBRARY gsl)
find_library(GSLCBLAS_LIBRARY gslcblas)

#find_library(PCRE_LIBRARY pcre)

include_directories(src)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -finline-functions -ffast-math -fstrength-reduce")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")


set(SRC_DIR src)
set(LDM_SRC 
	${SRC_DIR}/main.cpp
		

	${SRC_DIR}/utils/logger/Logger.h

	${SRC_DIR}/utils/test/Test.cpp
	${SRC_DIR}/utils/test/TestResult.cpp
	${SRC_DIR}/utils/test/TestSuite.cpp
)



add_executable(main ${LDM_SRC})

target_link_libraries(main ${GSL_LIBRARY} ${GSLCBLAS_LIBRARY} )
