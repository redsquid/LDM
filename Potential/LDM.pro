TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
#CONFIG += c++11

SOURCES += main.cpp \
    utils/test/Test.cpp \
    utils/test/TestResult.cpp \
    utils/test/TestSuite.cpp \
    utils/logger/Logger.cpp \
    potential/Shape.cpp \
    potential/CoulombEnergySharp.cpp \
    potential/SurfaceEnergySharp.cpp \
    test/potential/CoulumbEnergySharpTest.cpp \
    test/potential/SurfaceEnergySharpTest.cpp \
    test/potential/SurfaceEnergyTest.cpp \
    potential/const/GaussTable.cpp \
    potential/CoulombEnergy.cpp \
    potential/Potential.cpp \
    test/potential/PotentialTest.cpp \
    potential/SurfaceEnergy.cpp \
    potential/Volume.cpp \
    test/potential/VolumeTest.cpp \
    potential/RotationEnergySharp.cpp \
    test/potential/RotationEnergySharpTest.cpp \
    potential/RotationEnergy.cpp \
    test/potential/RotationEnergyTest.cpp \
    test/potential/CoulumbEnergyTest.cpp

HEADERS += \
    utils/test/ITest.h \
    utils/test/Test.h \
    utils/test/TestResult.h \
    utils/test/TestSuite.h \
    utils/logger/Logger.h \
    potential/Constants.h \
    potential/Shape.h \
    potential/const/Const.h \
    potential/Potential.h \
    potential/CoulombEnergySharp.h \
    potential/SurfaceEnergySharp.h \
    test/potential/PotentialMainTest.h \
    test/potential/CoulumbEnergySharpTest.h \
    test/potential/SurfaceEnergySharpTest.h \
    potential/const/GaussTable.h \
    potential/CoulombEnergy.h \
    potential/Potential.h \
    test/potential/PotentialTest.h \
    potential/SurfaceEnergy.h \
    potential/Volume.h \
    test/potential/VolumeTest.h \
    potential/RotationEnergySharp.h \
    test/potential/RotationEnergySharpTest.h \
    test/potential/SurfaceEnergyTest.h \
    potential/CoulumbEnergySharpParams.h \
    potential/params/CoulumbEnergySharpParams.h \
    potential/RotationEnergy.h \
    test/potential/RotationEnergyTest.h \
    test/potential/CoulumbEnergyTest.h

QMAKE_CXXFLAGS += -std=c++11 -g -Wall -Werror -finline-functions -ffast-math -fstrength-reduce

unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lgsl

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libgsl.a

unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lgslcblas

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libgslcblas.a
