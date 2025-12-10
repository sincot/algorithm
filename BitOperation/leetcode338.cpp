// 题目链接：https://leetcode.cn/problems/counting-bits/description/

class Solution {
public:
    vector<int> countBits(int n) {
        // 返回值
        vector<int> ret(n + 1);

        for(int i = 0; i <= n; i++)
        {
            // 统计i中1的个数
            int count = 0;

            int k = i;
            while(k)
            {
                k &= (k-1);
                count++;
            }
            ret[i] = count;
        }

        return ret;
    }
};
