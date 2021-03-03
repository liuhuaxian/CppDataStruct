TEMPLATE = app
CONFIG += console
CONFIG -= qt
QT += core

SOURCES += main.cpp \
    Exception.cpp \
    object.cpp

HEADERS += \
    Exception.h \
    List.h \
    SmartPointer.h \
    Object.h \
    SqlList.h \
    StaticList.h \
    DynamicList.h

