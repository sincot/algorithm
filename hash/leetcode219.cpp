// 题目链接：https://leetcode.cn/problems/contains-duplicate-ii/description/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 创建hash表
        unordered_map<int, int> hash;

        // 遍历nums数组
        for(int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];
            // 如果hash表中存在等于val的元素，且对应元素的下标相减小于等于k，直接返回true
            if(hash.count(val) && i - hash[val] <= k) { return true;}
            // 如果hash表中不存在等于val的元素，或者对应元素的下标相减不小于等于k，加入到hash表中
            hash[val] = i;
        }

        return false;
    }
};
