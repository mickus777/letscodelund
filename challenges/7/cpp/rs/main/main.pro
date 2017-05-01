TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ord.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ord.h

QMAKE_CXXFLAGS += -std=c++14
