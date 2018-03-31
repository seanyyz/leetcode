#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <set>
#include <iostream>
#include <iterator>

#include <3-sum/Solution.hpp>

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

    bool IsEqual(std::set<std::multiset<int>> expect, const std::vector<std::vector<int>> &actual)
    {
        if (expect.size() != actual.size())
        {
            return false;
        }
        const size_t size = actual.size();
        for (auto &&v : actual)
        {
            std::multiset<int> s(v.begin(), v.end());
            expect.erase(s);
        }
        return expect.empty();
    }

    template <typename Iterator>
    void Print(Iterator begin, Iterator end)
    {
        std::cout << "[";
        for (auto it = begin; it != end; it++)
        {
            if (it != begin)
            {
                std::cout << ", ";
            }
            std::cout << "[";
            for (auto its = it->begin(); its != it->end(); its++)
            {
                if (its != it->begin())
                {
                    std::cout << ", ";
                }
                std::cout << (*its);
            }
            std::cout << "]";
        }
        std::cout << "]" << std::endl;
    }
};

#define MY_EXPECT_EQ(expect, actual)                                   \
    bool res = IsEqual(expect, actual);                                \
    if (!res)                                                          \
    {                                                                  \
        GTEST_NONFATAL_FAILURE_("Expected equality of these values:"); \
        std::cout << "  Expected:" << std::endl;                       \
        std::cout << "    ";                                           \
        Print(expect.begin(), expect.end());                           \
        std::cout << "  Actual: " << std::endl;                        \
        std::cout << "    ";                                           \
        Print(actual.begin(), actual.end());                           \
    }

TEST_F(ThreeSumTest, Example)
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto actual = solution.threeSum(nums);
    std::set<std::multiset<int>> expect = {{-1, 0, 1}, {-1, -1, 2}};
    MY_EXPECT_EQ(expect, actual);
}

TEST_F(ThreeSumTest, SoManyZeros)
{
    std::vector<int> nums(1024, 0);
    auto actual = solution.threeSum(nums);
    std::set<std::multiset<int>> expect = {{0, 0, 0}};
    MY_EXPECT_EQ(expect, actual);
}

TEST_F(ThreeSumTest, Empty)
{
    std::vector<int> nums = {};
    auto actual = solution.threeSum(nums);
    std::set<std::multiset<int>> expect = {};
    MY_EXPECT_EQ(expect, actual);
}

TEST_F(ThreeSumTest, DuplicateNumbers)
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4, 2, 1, 0, -1, -4, 1, -1, -4, -4, 0};
    auto actual = solution.threeSum(nums);
    std::set<std::multiset<int>> expect = {{-1, 0, 1}, {-1, -1, 2}, {0, 0, 0}, {-4, 2, 2}};
    MY_EXPECT_EQ(expect, actual);
}

#undef MY_EXPECT_EQ
