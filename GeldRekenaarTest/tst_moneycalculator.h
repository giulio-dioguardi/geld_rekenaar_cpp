#ifndef TST_MONEYCALCULATOR_H
#define TST_MONEYCALCULATOR_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <moneycalculator.h>

using namespace testing;

TEST(TestMoneyCalculator, getValueZero)
{
    MoneyCalculator calculator;
    ASSERT_EQ(0, calculator.value());
}

TEST(TestMoneyCalculator, getSomeValue)
{
    MoneyCalculator calculator;
    calculator.addMoneyValue(MoneyValue(3, 50));
    ASSERT_EQ(150, calculator.centValue());
}

TEST(TestMoneyCalculator, getMultiplecentValues)
{
    MoneyCalculator calculator;
    calculator.addMoneyValue(MoneyValue(3, 50));
    calculator.addMoneyValue(MoneyValue(3, 100));
    calculator.addMoneyValue(MoneyValue(3, 200));
    ASSERT_EQ(1050, calculator.centValue());
}

TEST(TestMoneyCalculator, getMultipleValues)
{
    MoneyCalculator calculator;
    calculator.addMoneyValue(MoneyValue(3, 50));
    calculator.addMoneyValue(MoneyValue(3, 100));
    calculator.addMoneyValue(MoneyValue(3, 200));
    ASSERT_EQ(10.50, calculator.value());
}
#endif // TST_MONEYCALCULATOR_H
