// 题目链接：https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // 创建hash表
        unordered_map<int, int> hash;
        hash[0 % k] = 1;    // 特殊处理
        // 统计以i位置结尾的前缀和
        int sum = 0;
        // 记录可被k整除的非空子数组的数目
        int count = 0;

        for(auto e : nums)
        {
            // 计算当前位置的前缀和
            sum += e;
            int ret = (sum % k + k) % k;    // 修正后的余数
            if(hash.count(ret)) { count += hash[ret]; }
            // 将当前的余数加入到hash表中
            hash[ret]++;
        }

        return count;
    }
};
