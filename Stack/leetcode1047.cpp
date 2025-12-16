// 题目链接：https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/

class Solution {
public:
    string removeDuplicates(string s) {
        // 使用数组模拟栈结构
        string ret;

        // 遍历字符串
        for(auto ch : s)
        {
            // 如果ret字符串为空，加入到字符串中
            // 或者遍历到的字符等于ret字符串的尾字符，加入字符串中
            if(ret.empty() || ch != ret.back()) { ret += ch; }
            // 如果遍历到的字符等于ret字符串中的尾字符，从字符串ret中删除
            else { ret.pop_back(); }
        }

        return ret;
    }
};
