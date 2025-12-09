// 题目链接：https://leetcode.cn/problems/matrix-block-sum/description/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // 计算二维数组mat的行和列
        int r = mat.size(), c = mat[0].size();

        // r+1,c+1 是为了方便处理边界
        vector<vector<int>> dp(r + 1, vector<int>(c + 1));
        // 预处理二维前缀和矩阵
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                // mat[i-1][j-1]是为了处理下标的映射关系
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        // 返回值
        vector<vector<int>> answer(r, vector<int>(c));
        // 使用二维数组前缀和
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                int x1 = max(0, i - k) + 1, y1 = max(0, j - k) + 1;
                int x2 = min(r - 1, i + k) + 1, y2 = min(c - 1, j + k) + 1;
                answer[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
            }
        }

        return answer;
    }
};
