#include <string.h>
#include <vector>

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(grids, 0, sizeof(grids));

        for (size_t row = 0; row < 9; row++)
        {
            for (size_t col = 0; col < 9; col++)
            {
                const char c = board[row][col];
                if (c != '.')
                {
                    char num = c - '1';
                    int grid = row / 3 * 3 + col / 3;
                    if (rows[row][num] || columns[col][num] || grids[grid][num])
                    {
                        return false;
                    }
                    rows[row][num] = true;
                    columns[col][num] = true;
                    grids[grid][num] = true;
                }
            }
        }
        return true;
    }

private:
    bool rows[9][9];
    bool columns[9][9];
    bool grids[9][9];
};
