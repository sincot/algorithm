// 题目链接：https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

class Solution {
public:
    string modifyString(string s) {
        // 遍历
        for(int i = 0; i < s.length(); i++)
        {
            // 替换
            if(s[i] == '?')
            {
                for(char c = 'a'; c <= 'z'; c++)
                {
                    // 如果?在最左或最右，仅需比较后一个字符和前一个字符即可
                    if((i == 0 || s[i - 1] != c) && ((i == s.length() - 1) || s[i + 1] != c))
                    {
                        s[i] = c;
                        break;
                    }
                }
            }
        }

        return s;
    }
};
