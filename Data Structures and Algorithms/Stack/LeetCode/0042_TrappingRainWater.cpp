#include <iostream>
#include <stack>
#include <vector>

class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        int n = height.size();

        int left = 0;
        int right = n - 1;

        int leftMax = 0;
        int rightMax = 0;
        int totalWater = 0;

        while (left < right)
        {
            leftMax = std::max(leftMax, height[left]);
            rightMax = std::max(rightMax, height[right]);

            if (leftMax < rightMax)
            {
                totalWater += leftMax - height[left];
                left++;
            }
            else
            {
                totalWater += rightMax - height[right];
                right--;
            }
        }

        return totalWater;
    }
};

int main()
{
    std::vector<int> arr{4, 2, 0, 3, 2, 5};

    Solution solution;
    int res = solution.trap(arr);

    return 0;
}
