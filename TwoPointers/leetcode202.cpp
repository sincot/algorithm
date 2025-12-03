// 题目链接：https://leetcode.cn/problems/happy-number/description/
class Solution {
public:
    // 计算每个位置上的数字的平方和
    int TotalSs(int n)
    {
        int ret = 0;
        while(n)
        {
            int num = n % 10;
            ret += num * num;
            n /= 10;
        }

        return ret;
    }

    bool isHappy(int n) {
        // 定义快慢指针 --- 让快慢指针的初始至不同
        int slow = n;
        int fast = TotalSs(n);
        
        // 只要快慢指针相遇就跳出循环
        while(slow != fast)
        {
            // 慢指针走一步
            slow = TotalSs(slow);
            // 快指针走两步
            fast = TotalSs(TotalSs(fast));
        }

        return slow == 1;
    }
};
