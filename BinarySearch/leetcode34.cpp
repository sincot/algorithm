// 题目链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ret = { -1, -1 }; // 定义返回值
        
        // 查找左端点
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            // 若 mid < target,left = mid + 1
            if(nums[mid] < target){ left = mid + 1; }
            // 若 mid >= target,right = mid
            else{ right = mid; }
        }
        // 找到左端点
        if(left == right && nums[left] == target){ ret[0] = left; }

        // 重置
        left = 0;
        right = nums.size() - 1;

        // 查找右端点
        while(left < right)
        {
            int mid = left + (right - left + 1) / 2;
            // 若 mid > target,right = mid - 1
            if(nums[mid] > target){ right = mid - 1; }
            // 若 mid <= target,left = mid
            else{ left = mid; }
        }
        // 找右端点
        if(left == right && nums[right] == target){ ret[1] = right; }
       
        return ret;
    }
};
