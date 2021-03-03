TEMPLATE = app
CONFIG += console
CONFIG -= qt
QT += core

SOURCES += main.cpp \
    Exception.cpp \
    object.cpp

HEADERS += \
    Exception.h \
    SmartPointer.h \
    Object.h \
    SqlList.h \
    Array.h \
    StaticArray.h \
    DynamicArray.h

