// 题目链接：https://leetcode.cn/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 记录数组中和为k的子数组的个数
        int count = 0;
        // 创建hash表
        unordered_map<int, int> hash;
        hash[0] = 1;
        // 记录前一个位置的前缀和
        int sum = 0;

        for(auto e : nums)
        {
            sum += e;   // 计算当前位置的前缀和
            // 寻找当前位置之前,有多少个前缀和等于sum - k
            if(hash.count(sum - k)) { count += hash[sum - k]; }     // 统计个数
            // 前缀和加入到hash表中
            hash[sum]++;
        }

        return count;
    }
};
