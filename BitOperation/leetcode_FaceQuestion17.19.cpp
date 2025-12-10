// 题目链接：https://leetcode.cn/problems/missing-two-lcci/description/

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        // 整体序列的异或结果
        long all = 0;
        for(auto e : nums)
        {
            all ^= e;
        }
        for(int i = 1; i <= nums.size() + 2; i++)
        {
            all ^= i;
        }

        // 获取bitmap,即all中最右边为1的比特位
        long bitmap = all & (-all);

        // 分组
        int nums1 = 0, nums2 = 0;
        for(auto e : nums)
        {
            if(e & bitmap) { nums1 ^= e; }
            else { nums2 ^= e; }
        }
        for(int i = 1; i <= nums.size() + 2; i++)
        {
           if(i & bitmap) { nums1 ^= i; }
           else { nums2 ^= i; }
        }
        
        return {nums1, nums2};
    }
};
