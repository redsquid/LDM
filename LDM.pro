TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    utils/test/Test.cpp \
    utils/test/TestResult.cpp \
    utils/test/TestSuite.cpp \
    utils/logger/Logger.cpp \
    potential/CoulombEnergy.cpp \
    potential/Shape.cpp \
    potential/SurfaceEnergy.cpp \
    test/CoulumbEnergyTest.cpp \
    test/SurfaceEnergyTest.cpp

HEADERS += \
    utils/test/ITest.h \
    utils/test/Test.h \
    utils/test/TestResult.h \
    utils/test/TestSuite.h \
    utils/logger/Logger.h \
    potential/CoulombEnergy.h \
    potential/Constants.h \
    potential/Shape.h \
    potential/SurfaceEnergy.h \
    test/CoulumbEnergyTest.h \
    test/SurfaceEnergyTest.h \
    test/PotentialTest.h


unix: LIBS += -L$$PWD/../../../../usr/local/lib/ -lgsl

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix: PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/libgsl.a

unix: LIBS += -L$$PWD/../../../../usr/local/lib/ -lgslcblas

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix: PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/libgslcblas.a
