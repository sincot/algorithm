// 题目链接：https://leetcode.cn/problems/add-binary/description/

class Solution {
public:
    string addBinary(string a, string b) {
        // 相加是从末尾开始的，因此指针的初始指向字符串的末尾
        int cur1 = a.length() - 1, cur2 = b.length() - 1;
        int tmp = 0;    // 记录相加的结果
        string ret;     // 返回值
        // 循环 只要字符串a/b没有加完，或者还有进位
        while(cur1 >= 0 || cur2 >= 0 || tmp)
        {
            if(cur1 >= 0) { tmp += a[cur1--] - '0'; }
            if(cur2 >= 0) { tmp += b[cur2--] - '0'; }
            ret += tmp % 2 + '0';
            tmp /= 2;   // 进位
        }
        
        // 存的时候是倒着存，返回要正着返回
        reverse(ret.begin(), ret.end());

        return ret;
    }
};
