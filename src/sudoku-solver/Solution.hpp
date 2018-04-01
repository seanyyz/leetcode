#include <string.h>
#include <vector>

class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>> &board)
    {
        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(grids, 0, sizeof(grids));

        for (size_t row = 0; row < row_size; row++)
        {
            for (size_t col = 0; col < column_size; col++)
            {
                const char c = board[row][col];
                if (c != '.')
                {
                    rows[row][c - '1'] = true;
                    columns[col][c - '1'] = true;
                    grids[(row / 3) * 3 + col / 3][c - '1'] = true;
                }
            }
        }

        solveSudoku(board, 0, 0);
    }

private:
    // rows[i][num] : row i contains num, num use 0-8 to present 1-9
    bool rows[9][9];
    bool columns[9][9];
    bool grids[9][9];

    static const size_t row_size = 9;
    static const size_t column_size = 9;

    bool solveSudoku(std::vector<std::vector<char>> &board, int row, int col)
    {
        if (col == column_size)
        {
            if (row == (row_size - 1))
            {
                return true;
            }
            row++;
            col = 0;
        }

        if (board[row][col] != '.')
        {
            return solveSudoku(board, row, col + 1);
        }

        int grid = row / 3 * 3 + col / 3;
        for (char num = 0; num < 9; num++)
        {
            if (rows[row][num] || columns[col][num] || grids[grid][num])
            {
                continue;
            }

            board[row][col] = '1' + num;
            rows[row][num] = true;
            columns[col][num] = true;
            grids[grid][num] = true;

            if (solveSudoku(board, row, col + 1))
            {
                return true;
            }
            else
            {
                board[row][col] = '.';
                rows[row][num] = false;
                columns[col][num] = false;
                grids[grid][num] = false;
            }
        }

        return false;
    }
};
