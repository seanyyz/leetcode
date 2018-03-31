#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <median-of-two-sorted-arrays/Solution.hpp>

class MedianOfTwoSortedArraysTest : public ::testing::Test
{
protected:
    MedianOfTwoSortedArraysTest() {}
    virtual ~MedianOfTwoSortedArraysTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;

    std::vector<int> a0 = {};
    std::vector<int> a1 = {1, 3};
    std::vector<int> a2 = {2};
    std::vector<int> a3 = {1, 2};
    std::vector<int> a4 = {3, 4};
};

TEST_F(MedianOfTwoSortedArraysTest, Example)
{
    EXPECT_EQ(solution.findMedianSortedArrays(a1, a2), 2.0);
    EXPECT_EQ(solution.findMedianSortedArrays(a3, a4), 2.5);
}

TEST_F(MedianOfTwoSortedArraysTest, EmptyArray)
{
    EXPECT_EQ(solution.findMedianSortedArrays(a0, a2), 2.0);
    EXPECT_EQ(solution.findMedianSortedArrays(a3, a0), 1.5);
    EXPECT_TRUE(std::isnan(solution.findMedianSortedArrays(a0, a0)));
}