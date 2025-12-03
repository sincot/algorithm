// 题目链接：https://leetcode.cn/problems/move-zeroes/description/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dest = -1;
        int cur = 0;

        // cur 大于数组的元素个数之后说明修改完毕
        while(cur < nums.size()) 
        {
            if(nums[cur] != 0)
            {
                swap(nums[dest + 1], nums[cur]);
                dest++;
            }

            cur++;
        }
    }
};
