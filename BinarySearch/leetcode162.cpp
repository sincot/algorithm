// 题目链接：https://leetcode.cn/problems/find-peak-element/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 定义left和right指针
        int left = 0, right = nums.size() - 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            // 若 nums[mid] > nums[mid + 1],right = mid
            if(nums[mid] > nums[mid + 1]) { right = mid; }
            // 若 nums[mid] < nums[mid + 1],left = mid + 1
            else { left = mid + 1; }
        }

        return left;
    }
};
