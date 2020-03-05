#ifndef TST_NOTHING_H
#define TST_NOTHING_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <calculatorstub.h>

using namespace testing;

TEST(TestGeldRekenaar, getValueZero)
{
    CalculatorStub* s = new CalculatorStub();
    ASSERT_EQ(0, s->value());
}

#endif // TST_NOTHING_H
