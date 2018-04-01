#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sudoku-solver/Solution.hpp>

class SudokuSolverTest : public ::testing::Test
{
protected:
    SudokuSolverTest() {}
    virtual ~SudokuSolverTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }

    Solution solution;

    struct sudoku
    {
        std::vector<std::vector<char>> board;
        std::vector<std::vector<char>> answer;
    };

    sudoku sudoku1 = {
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
        {{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
         {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
         {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
         {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
         {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
         {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
         {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
         {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
         {'3', '4', '5', '2', '8', '6', '1', '7', '9'}}};

    sudoku sudoku2 = {
        {{'.', '.', '.', '4', '1', '.', '.', '.', '.'},
         {'.', '8', '.', '7', '.', '.', '2', '.', '.'},
         {'.', '7', '.', '.', '.', '.', '.', '5', '.'},
         {'.', '.', '6', '.', '.', '.', '3', '.', '.'},
         {'2', '.', '.', '.', '9', '6', '.', '7', '.'},
         {'.', '.', '.', '.', '8', '4', '.', '.', '.'},
         {'5', '3', '.', '.', '.', '.', '8', '.', '4'},
         {'.', '.', '.', '.', '.', '9', '.', '6', '.'},
         {'.', '4', '.', '.', '.', '1', '.', '.', '.'}},
        {{'9', '6', '2', '4', '1', '5', '7', '3', '8'},
         {'1', '8', '5', '7', '6', '3', '2', '4', '9'},
         {'3', '7', '4', '9', '2', '8', '6', '5', '1'},
         {'4', '9', '6', '1', '5', '7', '3', '8', '2'},
         {'2', '1', '8', '3', '9', '6', '4', '7', '5'},
         {'7', '5', '3', '2', '8', '4', '9', '1', '6'},
         {'5', '3', '1', '6', '7', '2', '8', '9', '4'},
         {'8', '2', '7', '5', '4', '9', '1', '6', '3'},
         {'6', '4', '9', '8', '3', '1', '5', '2', '7'}}};

    template <typename Iterator>
    void Print(Iterator begin, Iterator end)
    {
        std::cout << "{";
        for (auto it = begin; it != end; it++)
        {
            if (it != begin)
            {
                std::cout << ", ";
            }
            std::cout << "\n{'";
            for (auto its = it->begin(); its != it->end(); its++)
            {
                if (its != it->begin())
                {
                    std::cout << "', '";
                }
                std::cout << (*its);
            }
            std::cout << "'}";
        }
        std::cout << "}" << std::endl;
    }
};

#define MY_EXPECT_EQ(expect, actual)                                   \
    if (expect != actual)                                              \
    {                                                                  \
        GTEST_NONFATAL_FAILURE_("Expected equality of these values:"); \
        std::cout << "  Expected:" << std::endl;                       \
        Print(expect.begin(), expect.end());                           \
        std::cout << "  Actual: " << std::endl;                        \
        Print(actual.begin(), actual.end());                           \
    }

TEST_F(SudokuSolverTest, Example)
{
    solution.solveSudoku(sudoku1.board);
    MY_EXPECT_EQ(sudoku1.board, sudoku1.answer);
}

TEST_F(SudokuSolverTest, Hard)
{
    solution.solveSudoku(sudoku2.board);
    MY_EXPECT_EQ(sudoku2.board, sudoku2.answer);
}

#undef MY_EXPECT_EQ