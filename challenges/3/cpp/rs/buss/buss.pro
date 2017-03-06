TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    group.cpp \
    help.cpp

include(deployment.pri)
qtcAddDeployment()

QMAKE_CXXFLAGS += -std=c++14

HEADERS += \
    group.h \
    help.h

