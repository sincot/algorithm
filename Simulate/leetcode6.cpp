// 题目链接：https://leetcode.cn/problems/zigzag-conversion/description/

class Solution {
public:
    string convert(string s, int numRows) {
        // 特出处理,numRows等于0
        if(numRows == 1) { return s; }

        // 返回值
        string ret;
        // 计算公差 d
        int d = 2 * (numRows - 1);
        // 字符串的长度
        int len = s.length();

        // 处理第一行
        for(int i = 0; i < len; i += d) { ret += s[i]; }
        // 处理中间行
        for(int m = 1; m < numRows - 1; m++)
        {
            // 另一个
            for(int j = m, k = d - m; j < len || k < len; j += d, k += d)
            {
                // 先填充j,再填充k
                // 判断j是否越界
                if(j < len) { ret += s[j]; }
                // 判断k是否越界
                if(k < len) { ret += s[k]; }
            }
        }
        // 处理最后一行
        for(int i = numRows - 1; i < len; i += d) { ret += s[i]; }

        return ret;
    }
};
