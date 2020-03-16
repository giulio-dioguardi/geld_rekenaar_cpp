include(gtest_dependency.pri)
INCLUDEPATH += $$PWD/../MoneyCalculator

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread

HEADERS += \
        tst_moneycalculator.h \
        tst_moneyvalue.h \
        ../MoneyCalculator/moneycalculator.h \
        ../MoneyCalculator/moneycalculatormodel.h \
        ../MoneyCalculator/moneyvalue.h

SOURCES += \
        main.cpp \
        ../MoneyCalculator/moneycalculator.cpp \
        ../MoneyCalculator/moneycalculatormodel.cpp \
        ../MoneyCalculator/moneyvalue.cpp

