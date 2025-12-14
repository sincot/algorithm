// 题目链接：https://leetcode.cn/problems/contains-duplicate/description/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 创建hash表,由于不需要存下标，因此使用set
        unordered_set<int> hash;

        // 遍历nums数组
        for(int i = 0; i < nums.size(); i++)
        {
            // 如果hash表中存在nums[i]，直接返回true
            if(hash.count(nums[i])) { return true; }
            // 如果hash表中不存在nums[i]，加入hash表
            hash.insert(nums[i]);
        }

        // 出循环了，说明不存在重复的元素，返回false
        return false;
    }
};
