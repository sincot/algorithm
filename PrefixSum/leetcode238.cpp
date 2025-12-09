// 题目链接：https://leetcode.cn/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 数组 nums 元素的个数
        int n = nums.size();

        // 预处理前缀积和后缀积,不需要long long类型
        // 题目指出数组在32位整数范围内
        vector<int> prefix(n);      // 前缀积
        vector<int> suffix(n);      // 后缀积
        // 细节处理
        prefix[0] = 1;
        suffix[n - 1] = 1;

        // 填表 --- 前缀积prefix    从左向右
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        // 填表 --- 后缀积suffix    从右向左
        for(int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // 定义返回值
        vector<int> answer(n);
        // 使用prefix和suffix数组
        for(int i = 0; i < n; i++)
        {
            answer[i] = prefix[i] * suffix[i];
        }

        return answer;
    }
};
