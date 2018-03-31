#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <reverse-integer/Solution.hpp>

class ReverseIntegerTest : public ::testing::Test
{
protected:
    ReverseIntegerTest() {}
    virtual ~ReverseIntegerTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;
};

TEST_F(ReverseIntegerTest, Example)
{
    EXPECT_EQ(solution.reverse(123), 321);
    EXPECT_EQ(solution.reverse(-123), -321);
    EXPECT_EQ(solution.reverse(120), 21);
}

TEST_F(ReverseIntegerTest, Limits)
{
    EXPECT_EQ(solution.reverse(1463847412), 2147483641);
    EXPECT_EQ(solution.reverse(-1463847412), -2147483641);
    EXPECT_EQ(solution.reverse(2063847412), 2147483602);
    EXPECT_EQ(solution.reverse(-2063847412), -2147483602);
    EXPECT_EQ(solution.reverse(1563847412), 0);  // 2147483651 > INT_MAX
    EXPECT_EQ(solution.reverse(-1563847412), 0); // -2147483651 < INT_MIN
    EXPECT_EQ(solution.reverse(2147483647), 0);  // 7463847412 > INT_MAX
    EXPECT_EQ(solution.reverse(-2147483648), 0); // -8463847412 < INT_MIN
}
