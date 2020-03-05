#ifndef TST_NOTHING_H
#define TST_NOTHING_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(TestGeldRekenaar, nothing)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_NOTHING_H
