#include <string>

class Solution
{
public:
    // str: abcdefghijklmnopqrstuvwxyz, row = 4
    // a     g     m     s     y
    // b   f h   l n   r t   x z
    // c e   i k   o q   u w
    // d     j     p     v
    //
    // distance: distance from a to g, b to h ...
    // row: current proccessing row
    // next: distance from current charactor to next charactor at same row, e.g., b to f, f to h, c to e, e to i ...
    // rnext: distance from first charactor to next charactor at same row, e.g., b to f, c to e ...
    // pos: next writing charactor position to str
    std::string convert(std::string s, int numRows)
    {
        if(numRows < 2){
            return s;
        }
        std::string ret = s;
        const size_t size = s.length();
        const size_t distance = (numRows - 1) * 2;
        size_t row = 0;
        size_t next = distance;
        size_t rnext = distance;
        size_t pos = 0;
        for (size_t i = 0; i < size; i++)
        {
            ret[i] = s[pos];
            if (pos + next < size)
            {
                pos += next;
                if (next != distance)
                {
                    next = distance - next;
                }
            }
            else
            {
                row++;
                pos = row;
                rnext = (rnext == 2) ? (distance) : (rnext - 2);
                next = rnext;
            }
        }
        return ret;
    }
};
