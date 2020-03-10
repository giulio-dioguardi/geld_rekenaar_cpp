#ifndef TST_MONEYCALCULATOR_H
#define TST_MONEYCALCULATOR_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <moneycalculator.h>

using namespace testing;

TEST(TestMoneyCalculator, getValueZero)
{
    MoneyCalculator* s = new MoneyCalculator();
    ASSERT_EQ(0, s->value());
}
#endif // TST_MONEYCALCULATOR_H
