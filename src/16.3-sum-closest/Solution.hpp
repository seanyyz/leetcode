#include <vector>
#include <algorithm>
#include <cstdlib>

using std::sort;
using std::vector;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        const int len = nums.size();
        if (len < 3)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int diff = target - (nums[0] + nums[1] + nums[len - 1]);

        for (int i = 0; i < len - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1, right = len - 1;
            for (; left < right;)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(diff))
                {
                    diff = target - sum;
                }

                if (sum > target)
                {
                    for (; right > left && nums[right] == nums[right - 1];)
                    {
                        right--;
                    }
                    right--;
                }
                else if (sum < target)
                {
                    for (; left < right && nums[left] == nums[left + 1];)
                    {
                        left++;
                    }
                    left++;
                }
                else
                {
                    return target;
                }
            }
        }
        return target - diff;
    }
};
