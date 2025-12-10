// 题目链接：https://leetcode.cn/problems/number-of-1-bits/description/

class Solution {
public:
    int hammingWeight(int n) {
        // 计数器
        int count = 0;

        while(n)
        {
            // 将1变成0,有几个1就循环几次
            n &= (n - 1);
            count++;
        }

        return count;
    }
};
