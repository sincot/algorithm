// 题目链接：https://leetcode.cn/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 创建一个hash表
        unordered_map<string, vector<string>> hash;

        // 根据字符串排好序的结果进行分组
        for(string& str : strs)
        {
            // 将字符串排好序,不要对str操作
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            // 若排序后字符串相等,则进入同一个字符串数组
            // hash[tmp]的类型是vector<string>,可以调用push_back函数
            hash[tmp].push_back(str);
        }
        // 返回值
        vector<vector<string>> ret;
        // 遍历hash表
        for(auto& [k, v] : hash)
        {
            ret.push_back(v);
        }

        return ret;
    }
};
