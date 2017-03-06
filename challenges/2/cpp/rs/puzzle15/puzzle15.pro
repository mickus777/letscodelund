TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    help.cpp \
    plan.cpp \
    system.cpp

include(deployment.pri)
qtcAddDeployment()

QMAKE_CXXFLAGS += -std=c++14

HEADERS += \
    help.h \
    plan.h \
    system.h
