// 题目链接：https://leetcode.cn/problems/find-pivot-index/description/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // nums数组的元素个数
        int n = nums.size();
        // 预处理前缀和数组和后缀和数组
        vector<int> prefix(n);     // 前缀和数组
        vector<int> suffix(n);     // 后缀和数组
        // prefix 和 suffix 数组初始化内容为0

        // 填表 --- prefix前缀和表 从左向右填表
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        // 填表 --- suffix后缀和表 从右向左填表
        for(int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + nums[i + 1];
        }

        // 使用前缀和数组和后缀和数组
        for(int i = 0; i < n; i++)
        {
            if(prefix[i] == suffix[i])
            {
                return i;
            }
        }

        // 不存在中心下标,返回-1
        return -1;
    }
};
