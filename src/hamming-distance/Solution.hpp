#include <string>
#include <vector>
#include <stack>

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int z = x ^ y;
        int d = 0;
        for (; z > 0; z >>= 1)
        {
            d += z & 1;
        }
        return d;
    }
};
