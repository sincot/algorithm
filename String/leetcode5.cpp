// 题目链接：https://leetcode.cn/problems/longest-palindromic-substring/description/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        // 记录子串的起始位置和最长回文串的长度
        int flag = -1, maxlen = -1;
        // 找中心点
        for(int mid = 0; mid < len; mid++)
        {
            // 定义两个指针
            int left = mid, right = mid;    // 指向的相同的位置
            // 先找奇数长度
            while(left >= 0 && right < len && s[left] == s[right])
            { 
                left--;
                right++;
            }
            // 记录当前子串的起始位置与长度
            if(right - left - 1 > maxlen)
            {
                maxlen = right - left - 1;
                flag = left + 1;
            }
            // 再找偶数长度
            left = mid, right = mid + 1;    // 错开指向
            while(left >= 0 && right < len && s[left] == s[right])
            {
                left--;
                right++;
            }
            // 记录当前子串的起始位置与长度
            if(right - left - 1 > maxlen)
            {
                maxlen = right - left - 1;
                flag = left + 1;
            }
        }

        return s.substr(flag, maxlen);
    }
};
