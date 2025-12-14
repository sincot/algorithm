// 题目链接：https://leetcode.cn/problems/two-sum/description/

// 解法1：暴力解法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {j, i};
                }
            }
        }

        return { };
    }
};


// 解法2：hash表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 创建一个hash表 存的是元素和对应元素的下标
        unordered_map<int, int>hash(nums.size());
        // 遍历nums数组
        for(int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i];
            // 如果存在 target-nums[i],则直接返回
            if(hash.count(val)) { return {hash[val], i}; }
            // 如果不存在，加入hash表
            hash[nums[i]] = i;
        }
        
        return {};
    }
};
