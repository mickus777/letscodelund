TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bildaria.cpp \
    koch.cpp \
    help.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    bildaria.h \
    koch.h \
    help.h

QMAKE_CXXFLAGS += -std=c++14

QMAKE_CXXFLAGS += -Wl,-stack_size -Wl,1000000

#QMAKE_LFLAGS += -Wl
#QMAKE_LFLAGS += -Wl,-stack_size -Wl,1000000
