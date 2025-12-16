// 题目链接：https://leetcode.cn/problems/basic-calculator-ii/description/

class Solution {
public:
    int calculate(string s) {
        vector<int> st;     // 使用数组模拟栈结构
        int i = 0, n = s.length();  // 字符串的长度
        char charac = '+';      // 保存运算符

        // 遍历字符串s
        while(i < n)
        {
            if(s[i] == ' ') { i++; }   // 跳过空格字符
            // 判断是否是数字字符
            else if(s[i] >= '0' && s[i] <= '9')
            {
                // 提取数字字符中的数字
                int tmp = 0;
                // 不越界，并且是数字字符
                while(i < n && s[i] >= '0' && s[i] <= '9') { tmp = tmp*10 + (s[i++] - '0'); }

                // 根据charac保存的运算符，分情况讨论
                // 如果是 '+'，直接入栈
                if(charac == '+') { st.push_back(tmp); }
                // 如果是 '-'，将相反数入栈
                else if(charac == '-') { st.push_back(-1 * tmp); }
                // 如果是 '*'，取栈顶元素与之相乘
                else if(charac == '*') { st.back() *= tmp; }
                // 如果是 '/'，取栈顶元素与之相除
                else { st.back() /= tmp; }

                // 注意i不需要++，因为在提取字符时，就已经将数字字符跳过了
                // 当前i指向的就是运算符/空格
            }
            // 运算符，更新运算符
            else{ charac = s[i++]; }
        }

        // 跳出循环，将数组中的元素全部加在一起
        int ret = 0;
        for(auto e : st) { ret += e; }

        return ret;
    }
};
