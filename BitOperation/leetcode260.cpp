// 题目链接：https://leetcode.cn/problems/single-number-iii/description/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // long 类型防止溢出
        long all = 0;
        for(auto e : nums)
        {
            all ^= e;
        }

        // 获取all中的最低位的1，即最右边比特位为1
        // long 类型防止溢出
        long lowbit = all & (-all);

        // 分组
        int nums1 = 0, nums2 = 0;
        for(auto e : nums)
        {
            if(e & lowbit) { nums1 ^= e; }
            else { nums2 ^= e; }
        }

        return {nums1, nums2};
    }
};
