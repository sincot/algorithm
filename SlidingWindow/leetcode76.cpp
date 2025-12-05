// 题目链接：https://leetcode.cn/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        // 统计s的子串中字符出现的频次
        int hash1[128] = { 0 };
        //unordered_map<int, int> hash1;
        // 统计t的字符出现的频次
        int hash2[128] = { 0 };
        //unordered_map<int, int> hash2;
        int kinds = 0; // 统计 t 中有效字符个数
        // 统计t中字符出现的频次
        for(auto ch : t)
        {
            if(hash2[ch] == 0) { kinds++; }
            hash2[ch]++;
        }

        // 记录子串的长度
        int minlen = INT_MAX;
        // 记录子串的起始位置
        int begin = -1;

        // 定义left和right,count统计区间中有效字符的总类
        for(int left = 0, right = 0, count = 0; right < s.length(); right++)
        {
            // 进窗口
            hash1[s[right]]++;

            // 维护count
            // 当前字符为有效字符，且它出现的频次等于hash2,则count++
            if(hash1[s[right]] == hash2[s[right]])
            {
                count++;
            }

            // 判断 条件hash1中有效字符种类等于hash2中的元素种类
            while(count == kinds)
            {
                // 更新结果
                int len = right - left + 1;
                if(minlen > len)
                {
                    minlen = len;
                    begin = left;
                }
                // 维护count
                // 当前字符为有效字符，且它出现的频次等于hash2，则count--
                if(hash2[s[left]] == hash1[s[left]])
                {
                    count--;
                }
                // 出窗口
                hash1[s[left]]--;
                left++;
            }
        }

        // 没有找到子串
        if(begin == - 1) return "";

        return s.substr(begin, minlen);
    }
};
