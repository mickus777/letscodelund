TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    system.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    system.h

QMAKE_CXXFLAGS += -std=c++14
