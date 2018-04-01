#include <string>
#include <vector>
#include <stack>

class Solution
{
public:
    int evalRPN(std::vector<std::string> &&tokens)
    {
        const size_t size = tokens.size();
        std::stack<int> nums;
        for (uint32_t i = 0; i < size; i++)
        {
            std::string &s = tokens[i];
            if (s == "+")
            {
                int lhs = nums.top();
                nums.pop();
                nums.top() += lhs;
            }
            else if (s == "-")
            {
                int lhs = nums.top();
                nums.pop();
                nums.top() -= lhs;
            }
            else if (s == "*")
            {
                int lhs = nums.top();
                nums.pop();
                nums.top() *= lhs;
            }
            else if (s == "/")
            {
                int lhs = nums.top();
                nums.pop();
                nums.top() /= lhs;
            }
            else
            {
                nums.push(stoi(s));
            }
        }
        return nums.top();
    }
};
