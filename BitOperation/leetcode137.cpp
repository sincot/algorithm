// 题目链接：https://leetcode.cn/problems/single-number-ii/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 返回值
        int ret = 0;

        // 依次修改ret的每一位比特位
        for(int i = 0; i < 32; i++)
        {
            // 记录nums数组的所有元素的第i位比特位之和
            int sum = 0;
            for(auto e : nums)
            {
                // 获取 e 的第i位比特位
                sum += ((e >> i) & 1);
            }
            // 若 sum % 3 == 1,ret的第i位比特位变成1
            if(sum % 3 == 1) { ret |= (1 << i); }
        }

        return ret;
    }
};
