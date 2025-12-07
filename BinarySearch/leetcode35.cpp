// 题目链接：https://leetcode.cn/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            int x = nums[mid];

            // 若 x < target,left = mid + 1
            if(x < target) 
            { 
                left = mid + 1; 
            }
            // 若 x >= target,right = mid
            else { right = mid; }
        }

        // 如果target不存在nums,且插入的位置为数组的末端,返回left+1
        return nums[left] < target ? left + 1 : left;
    }
};
