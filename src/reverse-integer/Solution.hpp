class Solution
{
public:
    int reverse(int x)
    {
        int r = 0;
        for (; x != 0;)
        {
            if ((r > 214748364) || (r < -214748364))
            {
                return 0;
            }
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
};

// After solved this problem, I notice the (offical?) solution on leetcode
// in c++ check the case (r == INT_MAX / 10 && x > 7), but it's not going to
// happend.
// If r == 214748364, the input is _463847412 and the _ can only be 0 or 1,
// because the max value of int is 2147483647. 
// (And the same reason for negative case)
// 
// 解完這題後發現 leetcode 上的(官方?)解法檢查 (r == INT_MAX / 10 && x > 7) 但
// 這個狀況不會發生，若 r == 214748364 則輸入值是 _463847412 而 _ 只能是 0 或 1
// 因為 int 的上限是 2147483647。
// (負值的狀況同理)
