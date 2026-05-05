// 题目1： https://leetcode.cn/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n)
    {
        // 处理细节问题
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        int left = 0, mid = 1, right = 1, result = 0;   // 初始化
        for(int i = 3; i <= n; i++)
        {
            result = left + mid + right;
            left = mid, mid = right, right = result;    // 向后滚动
        }

        return result;
    }
};

// 题目2：https://leetcode.cn/problems/three-steps-problem-lcci/description/

class Solution {
public:
    int waysToStep(int n) {
        // 处理边界条件
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;

        const int MOD = 1000000007;
        // 1. 创建 dp 数组
        vector<int> dp(n + 1);
        // 2. 初始化
        dp[1] = 1, dp[2] = 2, dp[3] = 4;

        // 3. 填表
        for(int i = 4; i <= n; i++)
        {
            // 结果可能很大，需要对结果模 1000000007
            // 每次做加法时，都需要取模
            dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
        }

        // 4. 返回值
        return dp[n];
    }
};

// 题目3：https://leetcode.cn/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();

        // 1. 创建 dp 数组
        vector<int> dp(n);

        // 2. 初始化
        dp[n-1] = cost[n-1], dp[n-2] = cost[n-2];

        // 3. 填表 —— 从后向前
        for(int i = n - 3; i >= 0; i--)     dp[i] = min(dp[i+1], dp[i+2]) + cost[i];
        
        // 4. 返回值
        return min(dp[0], dp[1]);
    }
};

// 题目4：https://leetcode.cn/problems/decode-ways/description/

class Solution {
public:
    int numDecodings(string s)
    {
        int n = s.length();

        // 1. 创建 dp 数组
        vector<int> dp(n+1);

        // 2. 初始化
        dp[0] = 1;  // 保证后续的填表的是正确的
        dp[1] = s[1-1] != '0';  // 新dp表的 dp[1] 初始化与旧dp表的 dp[0] 初始化是一样的

        // 3. 填表 —— 从左往右
        for(int i = 2; i <= n; i++)
        {
            // 判断 i 位置是否可以单独编码
            if(s[i - 1] != '0') dp[i] += dp[i - 1];   // 处理单独编码的情况
            int num = (s[i-1-1]-'0')*10 + (s[i-1]-'0');   // 前两个位置的和
            if(num >= 10 && num <= 26) dp[i] += dp[i - 2];
        }

        // 4. 返回值
        return dp[n];
    }
};