#include <vector>
#include <set>
#include <algorithm>

using std::set;
using std::sort;
using std::vector;

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        const int len = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

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
                if (sum > 0)
                {
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    for (; left < right && nums[left] == nums[left - 1];)
                    {
                        left++;
                    }
                    for (; right > left && nums[right] == nums[right + 1];)
                    {
                        right--;
                    }
                }
            }
        }

        return ret;
    }
};
