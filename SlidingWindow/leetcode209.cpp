// 题目链接：https://leetcode.cn/problems/minimum-size-subarray-sum/description/

// 暴力枚举
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 暴力解法 --- 枚举出所有结果
        int minlen = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for(int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if(sum >= target)
                {
                    int len = j - i + 1;
                    minlen = min(len, minlen);
                }
            }
        }
        if(minlen == INT_MAX)
        {
            return 0;
        }

        return minlen;
    }
};

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(); // 序列的元素个数
        int sum = 0; // 计算区间的元素和
        int minlen = INT_MAX; // 将 minlen 设置为最大值，避免干扰结果

        for(int left = 0, right = 0; right < n; right++)
        {
            // 进窗口
            sum += nums[right];

            // 判断
            while(sum >= target)
            {
                // 计算区间的长度
                int len = right - left + 1;
                // 求最小长度
                minlen = min(len, minlen);
                // 求区间的元素和
                sum -= nums[left++];
            }
        }

        // 不存在符合条件的子数组 --- 直接返回0
        return minlen == INT_MAX ? 0 : minlen;
    }
};
