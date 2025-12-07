// 题目链接：https://leetcode.cn/problems/sqrtx/description/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    int mySqrt(int x) {
        // 考虑 x 小于1的情况
        if(x < 1)
        {
            return 0;
        }
        // 定义left和right指针
        int left = 1, right = x;

        while(left < right)
        {
            // 计算mid,x可能很大
            long long mid = left + (right - left + 1) / 2;
            // 若pow(mid) <= x,left = mid
            if(mid * mid <= x) { left = mid; }
            // 若pow(mid) > x,right = mid - 1
            else { right = mid - 1; }
        }

        return left;
    }
};
