// 题目链接：https://leetcode.cn/problems/contiguous-array/description/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 创建hash表,存储前缀和与子数组的长度
        unordered_map<int, int> hash;
        hash[0] = -1;   // 默认存在前缀和等于0的情况
        
        // 统计以i结尾的前缀和
        int sum = 0;
        // 记录满足条件的子数组的长度
        int maxlen = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            // 计算当前位置的前缀和
            sum += (nums[i] == 0 ? -1 : 1);
            // hash表中存在<sum,i>
            if(hash.count(sum)) { maxlen = max(maxlen, i - hash[sum]); }
            // hash表中不存在<sum,i>,将当前位置的长度加入到hash表中
            else { hash[sum] = i; }
        }

        return maxlen;
    }
};
