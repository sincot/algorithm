// 题目1： https://leetcode.cn/problems/the-masseuse-lcci/description/

class Solution {
public:
    int massage(vector<int>& nums)
    {
        if(nums.empty()) return 0;  // 处理数组为空的情况

        int n = nums.size();
        // 1. 创建 f[i] 和 g[i] 两张 dp 表
        vector<int> f(n), g(n);

        // 2. 初始化
        f[0] = nums[0], g[0] = 0;

        // 3. 填表 —— 从前往后
        for(int i = 1; i < n; i++)
        {
            f[i] = g[i-1] + nums[i];
            g[i] = max(f[i-1], g[i-1]);
        }

        // 4. 返回值 —— 最后一个位置可能不选，可能选，返回其中的最大值
        return max(f[n-1], g[n-1]);
    }
};

// 题目2：https://leetcode.cn/problems/house-robber-ii/description/

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();

        return max(nums[0] + rob1(nums, 2, n-2), rob1(nums, 1, n-1));    
    }

    int rob1(vector<int>& nums, int start, int end)
    {
        if(start > end) return 0;    // 空区间

        int n = nums.size();
        // 1. 创建 两张 dp 表
        vector<int> f(n), g(n);     // 不必考虑多开了空间，最终返回值时注意一下

        // 2. 初始化
        f[start] = nums[start];    // 初始化

        // 3. 填表 —— 从左往右（仅需填 [start, end] 范围即可）
        for(int i = start + 1; i <= end; i++)
        {
            f[i] = g[i-1] + nums[i];
            g[i] = max(f[i-1], g[i-1]);
        }

        // 4. 返回值
        return max(f[end], g[end]);
    }   
};

// 题目3：https://leetcode.cn/problems/delete-and-earn/description/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int n = nums.size(), m = 0;
        const int N = 10001;
        vector<int> arr(N);

        // 将nums中的元素统计到arr数组中
        for(auto e : nums) { m = max(m, e); arr[e] += e; }

        // 1. 创建 f,g 两张 dp 表
        vector<int> f(m+1), g(m+1);

        // 2. 初始化 —— 注意到 nums[i] 的最小值就是 1，因此在创建dp表时就已经初始化完毕了
        f[0] = arr[0], g[0] = 0;

        // 3. 填表
        for(int i = 1; i < m + 1; i++)
        {
            f[i] = g[i-1] + arr[i];
            g[i] = max(f[i-1], g[i-1]);
        }

        // 4. 返回值
        return max(f[m], g[m]);
    }
};

// 题目4：https://leetcode.cn/problems/JEj789/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int m = costs.size(), n = costs[0].size();
        // 1. 创建 dp 表
        vector<vector<int>> dp(m, vector<int>(n));
        
        // 2. 初始化
        dp[0] = costs[0];

        // 3. 填表
        for(int i = 1; i < m; i++)
        {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
        }
        
        // 4. 返回值
        return min(min(dp[m-1][0], dp[m-1][1]), dp[m-1][2]);
    }
};