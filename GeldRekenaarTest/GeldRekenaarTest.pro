include(gtest_dependency.pri)
INCLUDEPATH += $$PWD/..

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_nothing.h \
        ../calculatorstub.h

SOURCES += \
        main.cpp \
        ../calculatorstub.cpp

