#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string-to-integer-(atoi)/Solution.hpp>

class StringToIntegerTest : public ::testing::Test
{
protected:
    StringToIntegerTest() {}
    virtual ~StringToIntegerTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;
};

TEST_F(StringToIntegerTest, Example)
{
    EXPECT_EQ(solution.myAtoi("42"), 42);
    EXPECT_EQ(solution.myAtoi("   -42"), -42);
    EXPECT_EQ(solution.myAtoi("4193 with words"), 4193);
    EXPECT_EQ(solution.myAtoi("words and 987"), 0);
    EXPECT_EQ(solution.myAtoi("-91283472332"), -2147483648);
}

TEST_F(StringToIntegerTest, Limits)
{
    EXPECT_EQ(solution.myAtoi("2147483646"), 2147483646);
    EXPECT_EQ(solution.myAtoi("2147483647"), 2147483647);
    EXPECT_EQ(solution.myAtoi("10000000000"), 2147483647);
    EXPECT_EQ(solution.myAtoi("21474836470"), 2147483647);
    EXPECT_EQ(solution.myAtoi("-2147483647"), -2147483647);
    EXPECT_EQ(solution.myAtoi("-2147483648"), -2147483648);
    EXPECT_EQ(solution.myAtoi("-10000000000"), -2147483648);
    EXPECT_EQ(solution.myAtoi("-21474836480"), -2147483648);
}
