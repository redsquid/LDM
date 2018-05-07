cmake_minimum_required(VERSION 3.1)

# так пишутся комментарии

project(example)

find_library(GSL_LIBRARY gsl)
find_library(GSLCBLAS_LIBRARY gslcblas)

#find_library(PCRE_LIBRARY pcre)

include_directories(src)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")


set(SRC_DIR src)
set(LDM_SRC 
	${SRC_DIR}/main.cpp
		
	${SRC_DIR}/potential/const/GaussTable.cpp

	${SRC_DIR}/potential/params/CoulumbEnergySharpParams.cpp

	${SRC_DIR}/potential/CoulombEnergy.cpp
	${SRC_DIR}/potential/CoulombEnergySharp.cpp
	${SRC_DIR}/potential/FreeEnergy.cpp
	${SRC_DIR}/potential/Potential.cpp
	${SRC_DIR}/potential/RotationEnergy.cpp
	${SRC_DIR}/potential/RotationEnergySharp.cpp
	${SRC_DIR}/potential/Shape.cpp
	${SRC_DIR}/potential/SurfaceEnergy.cpp
	${SRC_DIR}/potential/SurfaceEnergySharp.cpp
	${SRC_DIR}/potential/Volume.cpp

	${SRC_DIR}/test/potential/CoulumbEnergySharpTest.cpp
    ${SRC_DIR}/test/potential/CoulumbEnergyTest.cpp
    ${SRC_DIR}/test/potential/FreeEnergyTest.cpp
    ${SRC_DIR}/test/potential/PotentialTest.cpp
    ${SRC_DIR}/test/potential/RotationEnergySharpTest.cpp
    ${SRC_DIR}/test/potential/RotationEnergyTest.cpp
    ${SRC_DIR}/test/potential/SurfaceEnergySharpTest.cpp
    ${SRC_DIR}/test/potential/SurfaceEnergyTest.cpp
    ${SRC_DIR}/test/potential/VolumeTest.cpp

	${SRC_DIR}/utils/logger/Logger.h

	${SRC_DIR}/utils/test/Test.cpp
	${SRC_DIR}/utils/test/TestResult.cpp
	${SRC_DIR}/utils/test/TestSuite.cpp
)



add_executable(main ${LDM_SRC})

target_link_libraries(main ${GSL_LIBRARY} ${GSLCBLAS_LIBRARY} )
