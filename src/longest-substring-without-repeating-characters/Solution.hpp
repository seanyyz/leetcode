#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::vector<int> last_pos(256, -1);
        int len = 0, start = -1;
        const int slen = s.length();
        for (int i = 0; i != slen; i++)
        {
            if (last_pos[s[i]] > start)
            {
                start = last_pos[s[i]];
            }
            last_pos[s[i]] = i;
            len = std::max(len, i - start);
        }
        return len;
    }
};
