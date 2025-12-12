// 题目链接：https://leetcode.cn/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, cur = 0, right = nums.size();
        
        while(cur < right)
        {
            // nums[cur] == 0,left++,swap(nums[left], nums[cur]),cur++
            if(nums[cur] == 0) { swap(nums[++left], nums[cur++]); }
            // nums[cur] == 2,right--,swap(nums[right], nums[cur])
            else if(nums[cur] == 2) { swap(nums[--right], nums[cur]); }
            // nums[cur] == 1,cur++
            else { cur++; }
        }
    }
};
