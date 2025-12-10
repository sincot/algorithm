// 题目链接：https://leetcode.cn/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 返回值
        int ret = 0;
        // 将 nums 数组中的元素异或在一起
        for(auto e : nums) { ret ^= e; }

        // 再将ret与[0,n]异或
        for(int i = 0; i <= nums.size(); i++) { ret ^= i; }

        return ret;
    }
};
