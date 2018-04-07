#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>

#include <16.3-sum-closest/Solution.hpp>

class ThreeSumTest : public ::testing::Test
{
protected:
    ThreeSumTest() {}
    virtual ~ThreeSumTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;

    std::string TestCaseString(std::vector<int> nums, int target)
    {
        std::string ret = "[";
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i != 0)
            {
                ret += ", ";
            }
            ret += std::to_string(nums[i]);
        }
        ret += "]\n";
        ret += "target=" + std::to_string(target);
        return ret;
    }
};

#define MY_EXPECT_EQ(expect, actual, input)       \
    if (expect != actual)                         \
    {                                             \
        GTEST_NONFATAL_FAILURE_("Wrong Answer:"); \
        std::cout << "  Input:" << std::endl;     \
        std::cout << input << std::endl;          \
        std::cout << "  Expected:" << std::endl;  \
        std::cout << expect << std::endl;         \
        std::cout << "  Actual: " << std::endl;   \
        std::cout << actual << std::endl;         \
    }

TEST_F(ThreeSumTest, Example)
{
    std::vector<int> nums = {-1, 2, 1, -4};
    int actual = solution.threeSumClosest(nums, 1);
    int expect = 2;
    std::string input = TestCaseString(nums, 1);
    MY_EXPECT_EQ(expect, actual, input);
}

TEST_F(ThreeSumTest, SoManyZeros)
{
    std::vector<int> nums(1024, 0);
    int actual = solution.threeSumClosest(nums, 1);
    int expect = 0;
    std::string input = TestCaseString(nums, 1);
    MY_EXPECT_EQ(expect, actual, input);
}

TEST_F(ThreeSumTest, NegativeTarget)
{
    std::vector<int> nums(4, 1);
    int actual = solution.threeSumClosest(nums, -100);
    int expect = 3;
    std::string input = TestCaseString(nums, -100);
    MY_EXPECT_EQ(expect, actual, input);
}

TEST_F(ThreeSumTest, ZeroTarget)
{
    std::vector<int> nums(4, 1);
    int actual = solution.threeSumClosest(nums, 0);
    int expect = 3;
    std::string input = TestCaseString(nums, 0);
    MY_EXPECT_EQ(expect, actual, input);
}


#undef MY_EXPECT_EQ
