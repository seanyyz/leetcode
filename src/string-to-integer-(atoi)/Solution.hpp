#include <string>

class Solution
{
public:
    int myAtoi(std::string str)
    {
        int ret = 0;
        size_t i = 0;
        size_t size = str.length();
        for (; i < size && str[i] == ' '; i++)
        {
        }
        if (i == size)
        {
            return ret;
        }

        bool neg = false;
        if (str[i] == '-')
        {
            neg = true;
            i++;
        }
        else if (str[i] == '+')
        {
            i++;
        }

        for (; i < size; i++)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                return neg ? -ret : ret;
            }
            if (ret > 214748364 || (ret == 214748364 && str[i] > '7'))
            {
                return neg ? -2147483648 : 2147483647;
            }
            ret = ret * 10 + (str[i] - '0');
        }
        return neg ? -ret : ret;
    }
};
