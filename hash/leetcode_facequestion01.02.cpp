// 题目链接：https://leetcode.cn/problems/check-permutation-lcci/description/

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length() != s2.length()) { return false; }

        // 使用数组模拟hash表
        int hash[26] = { 0 };
        // 加入hash表
        for(auto ch : s1) { hash[ch - 'a']++; }
        for(auto ch : s2)
        {
            hash[ch - 'a']--;
            // 如果出现负数，直接返回false
            if(hash[ch - 'a'] < 0) { return false; }
        }

        return true;
    }
};
