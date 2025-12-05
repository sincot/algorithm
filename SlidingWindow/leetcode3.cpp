// 题目链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/

// 暴力解法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 暴力解法
        // 计算最长子串的长度
        int maxlen = 0;
        // 固定起始位置
        for(int i = 0; i < s.length(); i++)
        {
            unordered_map<int, int>hash;  // 统计遍历区间的字符出现的频次
            for(int j = i; j < s.length(); j++)
            {
                // 如果字符在hash表中不存在，就插入hash
                hash[s[j]]++;

                // 如果字符在hash表中存在，就跳出循环
                if(hash[s[j]] > 1)
                {
                    break;
                }

                // 如果没有重复就更新子串的长度
                maxlen = max(maxlen, j - i + 1);
            }
        }

        return maxlen;
    }
};


// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 统计区间字符出现的频次
        //unordered_map<int, int>hash;
        
        int hash[128] = { 0 };  //使用数组来模拟hash表
        // 统计最长字符的长度
        int maxlen = 0;
        // 定义两个指针
        for(int left = 0, right = 0; right < s.length(); right++)
        {
            // 进窗口
            hash[s[right]]++;

            // 循环判断
            while(hash[s[right]] > 1)
            {
                // 出窗口
                hash[s[left]]--;
                left++;
            }

            // 更新结果
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};
