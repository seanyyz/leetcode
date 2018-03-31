#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        const size_t len1 = nums1.size();
        const size_t len2 = nums2.size();
        const size_t size = len1 + len2;
        const size_t target1Index = (size - 1) >> 1;
        const size_t target2Index = (size) >> 1;
        int target1;
        size_t i1 = 0;
        size_t i2 = 0;
        for (size_t i = 0; i < size; i++)
        {
            int num;

            if (i1 == len1)
            {
                num = nums2[i2];
                i2++;
            }
            else if (i2 == len2)
            {
                num = nums1[i1];
                i1++;
            }
            else
            {
                if (nums1[i1] > nums2[i2])
                {
                    num = nums2[i2];
                    i2++;
                }
                else
                {
                    num = nums1[i1];
                    i1++;
                }
            }

            if (i == target1Index)
            {
                target1 = num;
            }
            if (i == target2Index)
            {
                return (target1 + num) / 2.0;
            }
        }
        return std::nan("");
    }
};
