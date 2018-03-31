#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <zigzag-conversion/Solution.hpp>

class ZigZagConversionTest : public ::testing::Test
{
protected:
    ZigZagConversionTest() {}
    virtual ~ZigZagConversionTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;
};

TEST_F(ZigZagConversionTest, Example)
{
    std::string actual = solution.convert("PAYPALISHIRING", 3);
    std::string expect = "PAHNAPLSIIGYIR";
    EXPECT_EQ(actual, expect);

    actual = solution.convert("PAYPALISHIRING", 4);
    expect = "PINALSIGYAHRPI";
    EXPECT_EQ(actual, expect);
}
