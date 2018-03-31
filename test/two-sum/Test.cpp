#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <two-sum/Solution.hpp>

class TwoSumTest : public ::testing::Test
{
protected:
    TwoSumTest() {}
    virtual ~TwoSumTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;
};

TEST_F(TwoSumTest, Example)
{
    std::vector<int> nums = {2, 7, 11, 15};
    EXPECT_THAT(solution.twoSum(nums, 9), testing::ElementsAre(0, 1));
    EXPECT_THAT(solution.twoSum(nums, 13), testing::ElementsAre(0, 2));
    EXPECT_THAT(solution.twoSum(nums, 17), testing::ElementsAre(0, 3));
    EXPECT_THAT(solution.twoSum(nums, 18), testing::ElementsAre(1, 2));
    EXPECT_THAT(solution.twoSum(nums, 22), testing::ElementsAre(1, 3));
    EXPECT_THAT(solution.twoSum(nums, 26), testing::ElementsAre(2, 3));
}

TEST_F(TwoSumTest, DuplicateNumbers)
{
    std::vector<int> nums = {1, 2, 7, 7, 10, 11, 15};
    EXPECT_THAT(solution.twoSum(nums, 3), testing::ElementsAre(0, 1));
    EXPECT_THAT(solution.twoSum(nums, 8), testing::ElementsAre(0, 2));
    EXPECT_THAT(solution.twoSum(nums, 9), testing::ElementsAre(1, 2));
    EXPECT_THAT(solution.twoSum(nums, 11), testing::ElementsAre(0, 4));
    EXPECT_THAT(solution.twoSum(nums, 12), testing::ElementsAre(1, 4));
    EXPECT_THAT(solution.twoSum(nums, 13), testing::ElementsAre(1, 5));
    EXPECT_THAT(solution.twoSum(nums, 14), testing::ElementsAre(2, 3));
    EXPECT_THAT(solution.twoSum(nums, 16), testing::ElementsAre(0, 6));
    EXPECT_THAT(solution.twoSum(nums, 17), testing::ElementsAre(2, 4));
    EXPECT_THAT(solution.twoSum(nums, 18), testing::ElementsAre(2, 5));
    EXPECT_THAT(solution.twoSum(nums, 21), testing::ElementsAre(4, 5));
    EXPECT_THAT(solution.twoSum(nums, 22), testing::ElementsAre(2, 6));
    EXPECT_THAT(solution.twoSum(nums, 25), testing::ElementsAre(4, 6));
    EXPECT_THAT(solution.twoSum(nums, 26), testing::ElementsAre(5, 6));
}

TEST_F(TwoSumTest, Unordered)
{
    std::vector<int> nums = {11, 2, 15, 7, 10, 1, 7};
    EXPECT_THAT(solution.twoSum(nums, 3), testing::ElementsAre(1, 5));
    EXPECT_THAT(solution.twoSum(nums, 8), testing::ElementsAre(3, 5));
    EXPECT_THAT(solution.twoSum(nums, 9), testing::ElementsAre(1, 3));
    EXPECT_THAT(solution.twoSum(nums, 11), testing::ElementsAre(4, 5));
    EXPECT_THAT(solution.twoSum(nums, 12), testing::ElementsAre(1, 4));
    EXPECT_THAT(solution.twoSum(nums, 13), testing::ElementsAre(0, 1));
    EXPECT_THAT(solution.twoSum(nums, 14), testing::ElementsAre(3, 6));
    EXPECT_THAT(solution.twoSum(nums, 16), testing::ElementsAre(2, 5));
    EXPECT_THAT(solution.twoSum(nums, 17), testing::ElementsAre(1, 2));
    EXPECT_THAT(solution.twoSum(nums, 18), testing::ElementsAre(0, 3));
    EXPECT_THAT(solution.twoSum(nums, 21), testing::ElementsAre(0, 4));
    EXPECT_THAT(solution.twoSum(nums, 22), testing::ElementsAre(2, 3));
    EXPECT_THAT(solution.twoSum(nums, 25), testing::ElementsAre(2, 4));
    EXPECT_THAT(solution.twoSum(nums, 26), testing::ElementsAre(0, 2));
}