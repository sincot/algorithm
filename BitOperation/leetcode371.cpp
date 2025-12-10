// 题目链接：https://leetcode.cn/problems/sum-of-two-integers/description/

class Solution {
public:
    int getSum(int a, int b) {
        // 进位 a&b<<1 如果不等于0，就一直需要重复
        // (a ^ b)操作和(a&b << 1)操作
        while(b != 0)
        {
            int c = a ^ b;      // 无进位结果
            int d = (a & b) << 1;   // 进位
            a = c;
            b = d;
        }

        // 最终结果就是a
        return a;
    }
};
