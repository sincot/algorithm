// 题目链接：https://leetcode.cn/problems/longest-common-prefix/description/

class Solution {
public:
    // 求两个字符串的前缀
    string PrefixStr(const string& str1, const string& str2)
    {
        int i = 0;
        // 避免下标越界
        for(; i < str1.length() && i < str2.length(); i++)
        {
            if(str1[i] != str2[i]) { break; }
        }
        // 从0开始，截取i个字符
        return str1.substr(0, i);
    }

    string longestCommonPrefix(vector<string>& strs) {
        // 解法1：字符串两两比较
        string ret = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            ret = PrefixStr(ret, strs[i]);
        }

        return ret;
    }
};



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 解法2：统一比较
        // 以第一个字符串的长度为基准
        for(int i = 0; i < strs[0].length(); i++)
        {
            // 进行比较的基准值就是第一个字符串的第i个字符
            char privot = strs[0][i];
            // 遍历strs中的每一个字符串
            for(int j = 1; j < strs.size(); j++)
            {
                // 当某个字符串的字符不等于基准值时，返回
                // 或者i的大小等于字符串的长度,返回
                if(strs[j].length() == i || strs[j][i] != privot) { return strs[0].substr(0, i); }
            }
        }

        // 如果遍历比较所有字符串，仍然没有结果，返回第一个字符串
        return strs[0];
    }
};
