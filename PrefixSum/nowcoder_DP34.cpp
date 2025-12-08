// 题目链接：https://www.nowcoder.com/practice/acead2f4c28c401889915da98ecdc6bf?tpId=230&tqId=38960

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 第一行输入两个整数 n,m
    int n = 0, m = 0;
    cin >> n >> m;
    // 数组下标从1开始计数
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) { cin >> arr[i]; }

    // 预处理前缀和数组，数组名 dp
    // dp的元素类型为long long是为了防止溢出
    vector<long long> dp(n + 1);    
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + arr[i];
    }

    // 使用预处理数组
    while(m--)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl; 
    }

    return 0;
}
