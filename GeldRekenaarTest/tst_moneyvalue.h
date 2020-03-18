#ifndef TST_MONEYVALUE_H
#define TST_MONEYVALUE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <moneyvalue.h>

TEST(TestMoneyValue, getValueZero)
{
    MoneyValue moneyValue(0, 0);
    ASSERT_EQ(0, moneyValue.calculateTotalCentValue());
}

TEST(TestMoneyValue, getSomeValue)
{
    MoneyValue moneyValue(1, 100);
    ASSERT_EQ(100, moneyValue.calculateTotalCentValue());
}

TEST(TestMoneyValue, getSomeOtherValue)
{
    MoneyValue moneyValue(3, 50);
    ASSERT_EQ(150, moneyValue.calculateTotalCentValue());
}

TEST(TestMoneyValue, getADoubleZeroValue)
{
    MoneyValue moneyValue(0, 0);
    ASSERT_EQ(0.0, moneyValue.calculateTotalValue());
}

TEST(TestMoneyValue, getADoubleSomeValue)
{
    MoneyValue moneyValue(5, 50);
    ASSERT_EQ(2.5, moneyValue.calculateTotalValue());
}


#endif // TST_MONEYVALUE_H
