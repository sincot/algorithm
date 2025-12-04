// 题目链接：https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/

// 滑动窗口
// 推荐使用
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 创建两个hash表
        int hash1[26] = { 0 };  // s
        int hash2[26] = { 0 };  // p

        // 字符串p的长度
        int len = p.size();
        // 将字符串p加入至hash2中
        for(auto e : p)
        {
            hash2[e - 'a']++;
        }

        // 返回值
        vector<int> ret;

        // 标记有效字符出现的个数
        int count = 0;
        for(int left = 0, right = 0; right < s.size(); right++)
        {
            // 进窗口
            hash1[s[right] - 'a']++;
            if(hash1[s[right] - 'a'] <= hash2[s[right] - 'a'])
            {
                count++;
            }
            // 判断
            if(right - left + 1 > len)
            {
                // 出窗口
                if(hash1[s[left] - 'a'] <= hash2[s[left] - 'a'])
                {
                    count--;
                }
                hash1[s[left] - 'a']--;
                left++;
            }

            // 更新,判断两个数组是否相等
            if(count == len)
            {
                ret.push_back(left);
            }
        }

        return ret;
    }
};

// 判断hash表相等的条件有些复杂
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 创建两个hash表
        int hash1[26] = { 0 };   // s 字符串
        int hash2[26] = { 0 };   // p 字符串

        // 字符串p的长度
        int len = p.size();
        // 将字符串p加入至hash2中
        for(auto e : p)
        {
            hash1[e - 'a']++;
        }

        // 返回值
        vector<int> ret;

        for(int left = 0, right = 0; right < s.size(); right++)
        {
            // 进窗口
            hash2[s[right] - 'a']++;

            // 判断
            if(right - left + 1 > len)
            {
                // 出窗口
                hash2[s[left] - 'a']--;
                left++;
            }

            // 更新,判断两个数组是否相等
            int i = 0;
            for(auto e : hash1)
            {
                if(e != hash2[i])
                {
                    break;
                }

                i++;
            }
            if(i == 26) // 说明两个hash表相等
            {
                ret.push_back(left);
            }
        }

        return ret;
    }
};
