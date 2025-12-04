// 题目链接：https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/

// 滑动窗口
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0; //计算区间和
        int ret = INT_MAX; // 返回值初始值设为最大值
        int sum = 0; // 计算整个序列的元素和
        for(auto e : nums)
        {
            sum += e;
        }
        int n = nums.size(); // 数组的长度
        int target = sum - x;

        for(int left = 0, right = 0; right < n; right++)
        {
            total += nums[right]; // 进窗口

            // 判断
            while(left <= right && total > target)  // left <= right 避免越界
            {
                total -= nums[left++];
            }

            // total <= target
            if(total == target)
            {
                // 更新
                ret = min(ret, n - (right - left + 1));
            }
        }

        // 特殊处理，没有最佳解决方案
        return ret == INT_MAX ? -1 : ret;
    }
};


