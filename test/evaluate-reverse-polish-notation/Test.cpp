#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <evaluate-reverse-polish-notation/Solution.hpp>

class EvaluateReversePolishNotationTest : public ::testing::Test
{
protected:
    EvaluateReversePolishNotationTest() {}
    virtual ~EvaluateReversePolishNotationTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;
};

TEST_F(EvaluateReversePolishNotationTest, Example)
{
    EXPECT_EQ(solution.evalRPN({"2", "1", "+", "3", "*"}), 9);
    EXPECT_EQ(solution.evalRPN({"4", "13", "5", "/", "+"}), 6);
    EXPECT_EQ(solution.evalRPN({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}), 22);
}
