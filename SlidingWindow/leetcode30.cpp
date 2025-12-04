// 题目链接：https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/

// 滑动窗口
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // hash表
        unordered_map<string, int>hash2;    // 维护 words 中单词的频次

        // 将words中的字符串加入到hash2中
        for(auto& str : words)
        {
            hash2[str]++;
        }

        // 计算words中字符串的长度
        int len = words[0].size();
        // words中元素的个数
        int n = words.size();
        // 计算words的总长度
        int wordlen = n * len;
        
        //返回值
        vector<int> ret;
        // 滑动窗口的执行次数
        for(int i = 0; i < len; i++) // 滑动窗口滑动len次
        {
            unordered_map<string, int>hash1;    // 维护窗口内单词的频次
            // 定义两个指针，需要注意放入的字符串的长度应该为len
            for(int left = i, right = i, count = 0; right + len <= s.size(); right += len)
            {
                // 使用 substr 截取 s 中的字符串
                string str = s.substr(right, len);
                // 进窗口
                hash1[str]++;
                // 如果这个单词在words中，且频次未超过限制，更新count
                if(hash2.count(str) && hash1[str] <= hash2[str]){ count++; }

                // 判断 —— 尤其需要注意
                if(right - left + 1 > wordlen)
                {
                    // 使用 substr 截取 s 中的字符串
                    string str = s.substr(left, len);
                    // 如果这个单词在words中，且频次未超过限制，更新count
                    if(hash2.count(str) && hash1[str] <= hash2[str]) { count--; }
                    // 出窗口
                    hash1[str]--;
                    // left 向后移动
                    left += len;
                }

                // 更新结果
                if(count == n)
                {
                    ret.push_back(left);
                }
            }
        }

        return ret;
    }
};
