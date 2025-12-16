// 题目链接：https://leetcode.cn/problems/backspace-string-compare/description/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // 使用数组模拟栈结构
        string ret1;
        string ret2;

        // 遍历字符串 s
        for(auto ch : s)
        {
            if(ch != '#') { ret1 += ch; }
            if(ch == '#' && ret1.length()) { ret1.pop_back(); }
        }
        // 遍历字符串 t
        for(auto ch : t)
        {
            if(ch != '#') { ret2 += ch; }
            if(ch == '#' && ret2.length()) { ret2.pop_back(); }
        }
        // 求出两个字符串的长度
        int len1 = ret1.length(), len2 = ret2.length();
        // 如果两个字符串的长度不相等，字符串的内容一定不相等
        if(len1 != len2) { return false; }
        // 比较两个字符串是否相等
        for(int i = 0; i < len1; i++)
        {
            if(ret1[0] != ret2[0]) { return false; }
        }

        return true;
    }
};
