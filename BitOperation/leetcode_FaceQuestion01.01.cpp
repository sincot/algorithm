// 题目链接：https://leetcode.cn/problems/is-unique-lcci/description/

class Solution {
public:
    bool isUnique(string astr) {
        // 求字符串的长度
        int len = astr.length();
        // 小优化
        if(len > 26)
        {
            return false;
        }

        // 使用位图思想
        int bitmap = 0;
        for(auto ch : astr)
        {
            int index = ch - 'a';
            // 判断第 index 位是否为0，即是否存在
            // 存在，返回false
            if(((bitmap >> index) & 1) == 1) { return false; }
            // 不存在，将第index比特位变成1
            bitmap |= (1 << index);
        }

        return true;
    }
};
