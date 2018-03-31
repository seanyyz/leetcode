#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        const int len = nums.size();
        std::unordered_map<int, int> map;
        for (int i = 0; i < len; i++)
        {
            const auto foundIter = map.find(target - nums[i]);
            if ((foundIter != map.end()))
            {
                return std::vector<int>{foundIter->second, i};
            }
            map.emplace(nums[i], i);
        }
        throw std::runtime_error("Solution not found");
    }
};
