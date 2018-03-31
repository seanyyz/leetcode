#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <longest-palindromic-substring/Solution.hpp>

class LongestPalindromicSubstringTest : public ::testing::Test
{
protected:
    LongestPalindromicSubstringTest() {}
    virtual ~LongestPalindromicSubstringTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;
};

TEST_F(LongestPalindromicSubstringTest, Example)
{
    std::string actual = solution.longestPalindrome("babad");
    std::string expect = "bab";
    EXPECT_EQ(actual, expect);

    actual = solution.longestPalindrome("cbbd");
    expect = "bb";
    EXPECT_EQ(actual, expect);
}
