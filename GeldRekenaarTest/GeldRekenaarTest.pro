include(gtest_dependency.pri)
INCLUDEPATH += $$PWD/../MoneyCalculator

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_nothing.h \
        ../MoneyCalculator/moneycalculator.h

SOURCES += \
        main.cpp \
        ../MoneyCalculator/moneycalculator.cpp

