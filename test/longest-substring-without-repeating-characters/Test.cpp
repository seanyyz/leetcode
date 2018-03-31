#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <longest-substring-without-repeating-characters/Solution.hpp>

class LongestSubstringWithoutRepeatingCharactersTest : public ::testing::Test
{
protected:
    LongestSubstringWithoutRepeatingCharactersTest() {}
    virtual ~LongestSubstringWithoutRepeatingCharactersTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;
};

TEST_F(LongestSubstringWithoutRepeatingCharactersTest, Example)
{
    EXPECT_EQ(solution.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(solution.lengthOfLongestSubstring("bbbbbb"), 1);
    EXPECT_EQ(solution.lengthOfLongestSubstring("pwwkew"), 3);
}
