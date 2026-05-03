// 题目1：https://leetcode.cn/problems/path-with-maximum-gold/description/

class Solution {
    bool check[16][16];     // 检查某个格子是否走过了
    int m, n;       // 行与列
    int ret, path;  // 返回值与路径上的元素和
    // 向量来表示上下左右四个方位 —— (x-1, y) (x+1, y) (x, y-1) (x, y+1)
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // 选择起始位置
                if(grid[i][j] != 0)
                {
                    check[i][j] = true;
                    path += grid[i][j];
                    dfs(grid, i, j);
                    // 恢复现场
                    check[i][j] = false;
                    path -= grid[i][j];
                }
            }
        }

        return ret;
    }

    // i, j 表示起始位置的横纵坐标
    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            // 横纵坐标不能越界 并且 该位置不等于 0 并且 单元格没有被进入 
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0 && check[x][y] == false)
            {   
                check[x][y] = true;
                path += grid[x][y];
                dfs(grid, x, y);
                // 恢复现场
                check[x][y] = false;
                path -= grid[x][y];
            }
        }

        // 到了这一步，说明路径已经到头了，上不能上，下不能下，左不能左，右不能右，更新返回值
        ret = max(path, ret);
    }
};

// 题目2：https://leetcode.cn/problems/unique-paths-iii/description/

class Solution {
    int ret;
    vector<int> path;
    bool check[21][21];     // 记录某个格子是否被使用

    // (x-1, y) (x+1, y) (x, y-1) (x, y+1)
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    int count = 0;  // 有几个非'-1'的数字
    int sum = 0;    // 统计路径上的元素个数
    int m, n;       // 行 与 列
    int start_x, start_y;   // 起始位置的横纵坐标
    int end_x, end_y;       // 结束位置的横纵坐标

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();    // 行 与 列
        // 由于起始/结束位置仅有一个，因此可以找出起始位置与结束位置的横纵坐标
        // 为了满足题目的条件：每一个无障碍方格都要通过一次，因此可以统计有几个非 '-1' 的数字，便于判断
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != -1)
                {
                    if(grid[i][j] == 1) start_x = i, start_y = j;
                    if(grid[i][j] == 2) end_x = i, end_y = j;
                    count++;
                }
            }
        }

        // 起始位置找到了开始递归
        sum++;
        check[start_x][start_y] = true;
        dfs(grid, start_x, start_y);

        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i == end_x && j == end_y)    // 遍历到结束位置
        {
            if(sum == count) ret++;
            return;
        }

        // 上下左右四个方位
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != -1 && check[x][y] == false)
            {
                check[x][y] = true;
                sum++;
                dfs(grid, x, y);
                check[x][y] = false;
                sum--;
            }
        }
    }
};