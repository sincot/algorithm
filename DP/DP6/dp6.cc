// 题目1：https://leetcode.cn/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        // 1. 创建dp表
        vector<int> dp(n, 1);

        // 2. 初始化 —— 在建表时，就已经初始化完毕了

        // 3. 填表
        int ret = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])  dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }

        // 4. 返回值
        return ret;
    }
};


// 题目2：https://leetcode.cn/problems/wiggle-subsequence/description/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int n  = nums.size();
        // 1. 创建 f,g 两张表
        vector<int> f(n, 1), g(n, 1);

        // 2. 初始化 —— 在建表时，就已经初始化完毕了

        // 3. 填表
        int f_max = 1, g_max = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++) // 遍历 0~i-1 位置的元素
            {
                if(nums[i] > nums[j]) f[i] = max(f[i], g[j] + 1);
                if(nums[i] < nums[j]) g[i] = max(g[i], f[j] + 1);
            }
            f_max = max(f_max, f[i]), g_max = max(g_max, g[i]);
        }

        // 4. 返回值
        return max(f_max, g_max);
    }
};


// 题目3：https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        // 1. 创建 len,count 两张 dp 表
        vector<int> len(n, 1), count(n, 1);

        // 2. 初始化 —— 在建表时，就已经初始化完毕

        // 3. 填表
        int maxval = len[0], ret = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(len[j] + 1 == len[i])        count[i] += count[j];
                    else if(len[j] + 1 > len[i])    len[i] = len[j] + 1, count[i] = count[j];
                }
            }

            if(maxval == len[i])     ret += count[i];
            else if(maxval < len[i]) maxval = len[i], ret = count[i];
        }

        // 4. 返回值
        return ret;
    }
};


// 题目4：https://leetcode.cn/problems/maximum-length-of-pair-chain/description/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        sort(pairs.begin(), pairs.end());       // 对原序列预处理
        int n = pairs.size();
        // 1. 创建 dp 表
        vector<int> dp(n, 1);

        // 2. 初始化 —— 在建表时，就已经初始化了

        // 3. 填表
        int ret = dp[0];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(pairs[j][1] < pairs[i][0])   dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }

        // 4. 返回值
        return ret;
    }
};