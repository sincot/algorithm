// 题目链接：https://leetcode.cn/problems/multiply-strings/description/

class Solution {
public:
    string multiply(string num1, string num2) {
        // 求出两字符串的长度，方便创建数组tmp
        int m = num1.length(), n = num2.length();
        // 处理前导'0'问题 （字符串单独为0）
        if((m == 1 && num1[0] == '0') || (n == 1 && num2[0] == '0')) { return "0"; }
        // 逆序两个字符串
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // 创建一个数组存储字符相乘的结果
        vector<int> tmp(m + n - 1); // 初始化为0
        // 无进位相乘，再相加
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int num = (num1[i] - '0') * (num2[j] - '0');    // 字符相乘的结果
                // i下标和j下标的字符相乘，结果与i+j下标位置存储的元素相加
                tmp[i+j] += num;
            }
        }

        string ret;            // 返回值
        int temp = 0, i = 0;   // 存储相加的结果
        // 处理返回值
        while(i < tmp.size() || temp != 0)
        {
            if(i < tmp.size())
            {
                temp = tmp[i++] + temp;
            }
            ret += (temp%10 + '0');
            temp /= 10;     // 进位
        }
        // 处理前导'0'问题
        // 要保存最后的'0'，因此判断条件有字符串的长度要大于1
        //while(ret.length() > 1 && ret.back() == '0') { ret.pop_back(); }
        // 逆序
        reverse(ret.begin(), ret.end());

        return ret;
    }
};
