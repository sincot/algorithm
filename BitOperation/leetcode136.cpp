// 题目链接：https://leetcode.cn/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto e : nums)
        {
            ret ^= e;
        }

        return ret;
    }
};
