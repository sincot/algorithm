// 题目链接：https://leetcode.cn/problems/binary-search/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right)
        {
            // 这么初始化 mid 是为了避免溢出风险
            // int mid = (right + left) / 2;
            int mid = left + (right - left) / 2;

            // 当 mid > target,right = mid - 1
            if(nums[mid] > target) { right = mid - 1; }
            // 当 mid < target,left = mid + 1
            else if(nums[mid] < target) { left = mid + 1; }
            // 当 mid == targte,返回mid
            else { return mid; }
        }

        // 找不到，返回-1
        return -1;
    }
};
