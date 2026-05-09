// 题目1：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        // 1. 创建 m*3 的 dp 表
        vector<vector<int>> dp(m, vector<int>(3));

        // 2. 初始化
        dp[0][0] = -prices[0], dp[0][1] = dp[0][2] = 0;

        // 3. 填表
        for(int i = 1; i < m; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][2] = dp[i-1][0] + prices[i];
        }

        // 4. 返回值 —— 仅需比较 dp[m-1][1] 和 dp[m-1][2] 即可
        return max(dp[m-1][1], dp[m-1][2]);
    }
};

// 题目2：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();
        // 1. 创建 f,g 两张 dp 表
        vector<int> f(n), g(n);

        // 2. 初始化
        f[0] = -prices[0], g[0] = 0;

        // 3. 填表
        for(int i = 1; i < n; i++)
        {
            f[i] = max(f[i-1], g[i-1] - prices[i]);
            g[i] = max(g[i-1], f[i-1] + prices[i] - fee);
        }

        // 4. 返回值 —— 返回值 g[n-1]
        return g[n-1];
    }
};

// 题目3：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        const int INF = -0x3f3f3f3f;
        int n = prices.size();
        // 1. 创建 f,g 两张 dp 表
        vector<vector<int>> f(n, vector<int>(3, INF));
        vector<vector<int>> g(n, vector<int>(3, INF));

        // 2. 初始化
        f[0][0] = -prices[0], g[0][0] = 0;

        // 3. 填表
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= 2; j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                g[i][j] = g[i-1][j];
                if(j >= 1) g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
            }
        }

        // 4. 返回值 —— 找到 g 表中最后一行中的最大值
        int bonus = 0;
        for(int j = 0; j < 3; j++)  bonus = max(bonus, g[n-1][j]);

        return bonus;
    }
};

// 题目4：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int INF = -0x3f3f3f3f;
        int n = prices.size();
        k = min(k, n/2);    // 对 k 做处理
        // 1. 创建 f,g 两张 dp 表
        vector<vector<int>> f(n, vector<int>(k+1, INF));
        vector<vector<int>> g(n, vector<int>(k+1, INF));

        // 2. 初始化
        f[0][0] = -prices[0], g[0][0] = 0;

        // 3. 填表
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                g[i][j] = g[i-1][j];
                if(j >= 1) g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
            }
        }

        // 4. 返回值 —— 找到 g 表中最后一行中的最大值
        int bonus = 0;
        for(int j = 0; j <= k; j++)  bonus = max(bonus, g[n-1][j]);

        return bonus;
    }
};