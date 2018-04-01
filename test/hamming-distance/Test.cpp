#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <hamming-distance/Solution.hpp>

class HammingDistanceTest : public ::testing::Test
{
protected:
    HammingDistanceTest() {}
    virtual ~HammingDistanceTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;
};

TEST_F(HammingDistanceTest, Example)
{
    EXPECT_EQ(solution.hammingDistance(1, 4), 2);
}
