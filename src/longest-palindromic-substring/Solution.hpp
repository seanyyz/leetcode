#include <string>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        const int size = s.size();
        if (size < 2)
        {
            return s;
        }
        int max_start = 0, max_len = 1;
        const int sizem = size - 1;
        for (int i = 0; i < sizem;)
        {
            if (size - i <= max_len / 2)
                break;

            int start = i, end = i;

            for (; end < sizem && s[start] == s[end + 1];)
            {
                end++;
            }
            i = end + 1;

            for (; start > 0 && end < sizem && s[start - 1] == s[end + 1];)
            {
                start--;
                end++;
            }

            int nlen = end - start + 1;
            if (nlen > max_len)
            {
                max_start = start;
                max_len = nlen;
            }
        }
        return s.substr(max_start, max_len);
    }
};