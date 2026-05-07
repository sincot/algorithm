// 题目1：https://leetcode.cn/problems/unique-paths/description/

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        // 1. 创建 dp 表
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        // 2. 初始化
        dp[0][1] = 1;

        // 3. 填表 —— 从上向下/从左向右
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }

        // 4. 返回值
        return dp[m][n];
    }
};

// 题目2：https://leetcode.cn/problems/unique-paths-ii/description/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // 1. 创建 dp 表
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        // 2. 初始化
        dp[0][1] = 1;

        // 3. 填表
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(obstacleGrid[i-1][j-1] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        // 4. 返回值
        return dp[m][n];
    }
};

// 题目3：https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame)
    {
        int m = frame.size(), n = frame[0].size();
        // 1. 创建 dp 表
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        // 2. 初始化 —— 在创建dp表时，已经初始化了

        // 3. 填表 —— 从上往下/从左往右
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)     dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + frame[i-1][j-1];
        }

        // 4. 返回值
        return dp[m][n];
    }
};

// 题目4：https://leetcode.cn/problems/minimum-falling-path-sum/description/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        // 1. 创建 dp 表
        vector<vector<int>> dp(m+1, vector<int>(n+2));  // 新增1行和2列

        // 2. 初始化
        for(int i = 0; i < m+1; i++)   dp[i][0] = dp[i][n+1] = INT_MAX;     // 新增的两列中的值初始化成正无穷
        for(int j = 0; j < n+2; j++)   dp[0][j] = 0;                        // 新增的一行中的值初始化成 0

        // 3. 填表 —— 从上往下
        int minpath = INT_MAX;  // 记录最后一行中dp表的最小值
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]) + matrix[i-1][j-1];
                if(i == m) minpath = min(minpath, dp[i][j]);    
            }
        }

        // 4. 返回值 —— 最后一行 dp 表中的最小值
        return minpath;
    }
};

// 题目5：https://leetcode.cn/problems/minimum-path-sum/description/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        // 1. 创建 dp 表
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));

        // 2. 初始化
        dp[0][1] = dp[1][0] = 0;

        // 3. 填表 —— 从上往下/从左往右
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)     dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
        }

        // 4. 返回值
        return dp[m][n];
    }
};

// 题目6：https://leetcode.cn/problems/dungeon-game/description/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        // 1. 创建 dp 表
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));

        // 2. 初始化
        dp[m][n-1] = dp[m-1][n] = 1;

        // 3. 填表 —— 从下往上/从右往左
        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
                dp[i][j] = max(dp[i][j], 1);    // 避免dp[i][j]为负数
            }
        }

        // 4. 返回值
        return dp[0][0];
    }
};