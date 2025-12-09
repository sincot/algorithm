// 题目链接：https://www.nowcoder.com/practice/99eb8040d116414ea3296467ce81cbbc?tpId=230&tqId=2023819&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 读入三个整数 n,m,q
    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;
    // 向 arr 写入数据
    vector<vector<int>> arr(n+1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 类型为 long long 防止溢出
    vector<vector<long long>> dp(n+1, vector<long long>(m + 1));
    
    // 预处理前缀和 dp 矩阵
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + arr[i][j] - dp[i-1][j-1];
        }
    }

    // 使用前缀和 dp 矩阵
    while(q--)
    {
        // 输入 x1,y1,x2,y2
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << endl;
    }

    return 0;
}
