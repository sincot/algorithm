// 题目1：https://leetcode.cn/problems/flood-fill/description/

class Solution {
    int target;
    int m, n;   // 行 与 列
    // (x-1, y) (x+1, y) (x, y-1) (x, y+1)
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        target = image[sr][sc];    // 要寻找的数字
        m = image.size(), n = image[0].size();

        if(target == color) return image;  // 细节处理，防止死递归

        dfs(image, sr, sc, color);
        
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color)
    {
        image[sr][sc] = color;      // 修改数值

        for(int k = 0; k < 4; k++)
        {
            int x = sr + dx[k], y = sc + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && image[x][y] == target)
            {
                dfs(image, x, y, color);
            }
        }
    }
};

// 题目2：https://leetcode.cn/problems/number-of-islands/description/

class Solution {
    vector<vector<bool>> check;
    int m, n;
    int ret;

    // (x-1, y) (x+1, y) (x, y-1) (x, y+1)
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        check = vector<vector<bool>>(m, vector<bool>(n));

        // 找起始位置
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1' && check[i][j] == false)
                {
                    dfs(grid, i, j);    // 这里出来之后，说明已经找到一个岛屿了
                    ret++;
                }
            }
        }

        return ret;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        check[i][j] = true;

        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && check[x][y] == false && grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }
};

// 题目3：https://leetcode.cn/problems/max-area-of-island/description/

class Solution {
    int ret = 0;
    int step;
    vector<vector<bool>> check;

    int m, n;

    // (x-1, y) (x+1, y) (x, y-1) (x, y+1)
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        check = vector<vector<bool>>(m, vector<bool>(n));

        // 找起始位置
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && check[i][j] == false)
                {
                    step = 0;               
                    dfs(grid, i, j);        // 深度优先遍历
                    ret = max(step, ret);   // 找到并计算出了一个岛屿的面积
                }
            }
        }

        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        step++;                 // 找到一块陆地
        check[i][j] = true;     // 此位置已经被遍历了

        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && check[x][y] == false && grid[x][y] == 1)
            {
                dfs(grid, x, y);
            }
        }
    }
};

// 题目4：https://leetcode.cn/problems/surrounded-regions/description/

class Solution {
    int m, n;

    // (x-1, y) (x+1, y) (x, y-1) (x, y+1)
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        //  先处理边界的情况
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[m-1][j] == 'O') dfs(board, m-1, j);
        }

        // 遍历原数组，遇到 '.' 字符就变成 'O'，遇到 'O' 字符就变成 'X'
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')  board[i][j] = 'X';
                else if(board[i][j] == '.')  board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {   
        board[i][j] = '.';

        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O')
            {
                dfs(board, x, y);
            }
        }
    }
};

// 题目5：https://leetcode.cn/problems/pacific-atlantic-water-flow/description/

class Solution {
    vector<vector<int>> ret;
    int m, n;

    // (x-1, y) (x+1, y) (x, y-1) (x, y+1)
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific, atlantic;    // 太平洋 和 大西洋
        m = heights.size(), n = heights[0].size();
        pacific = atlantic = vector<vector<bool>>(m, vector<bool>(n));

        // 先处理太平洋
        for(int j = 0; j < n; j++) dfs(heights, pacific, 0, j);     // 左区域
        for(int i = 0; i < m; i++) dfs(heights, pacific, i, 0);     // 上区域

        // 再处理大西洋
        for(int j = 0; j < n; j++) dfs(heights, atlantic, m-1, j);  // 下区域
        for(int i = 0; i < m; i++) dfs(heights, atlantic, i, n-1);  // 右区域

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pacific[i][j] && atlantic[i][j]) ret.push_back({i, j});
            }
        }

        return ret;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& check, int i, int j)
    {
        check[i][j] = true;

        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j] && check[x][y] == false)
                dfs(heights, check, x, y);
        }
    }
};

// 题目6：https://leetcode.cn/problems/minesweeper/description/

class Solution {
    // 八个方位： (x-1, y) (x+1, y) (x, y-1) (x, y+1) (x-1, y-1) (x-1, y+1) (x+1, y-1) (x+1, y+1) 
    int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    int click_x, click_y;
    int m, n;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        click_x = click[0], click_y = click[1];
        m = board.size(), n = board[0].size();

        if(board[click_x][click_y] == 'M')  { board[click_x][click_y] = 'X'; return board; }
        bfs(board, click_x, click_y);

        return board;
    }

    void bfs(vector<vector<char>>& board, int i, int j)
    {
        int count = 0;
        // 问题：如何统计出雷的个数？沿着8个方位进行搜索 
        for(int k = 0; k < 8; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M')    count++;
        }

        // 统计出雷的个数，做不同情况的区分，周围存在地雷，周围不存在地雷
        if(count)   // 有雷
        {
            board[i][j] = count + '0';  // 修改成雷的个数
            return; // 直接返回
        }
        
        // 周围没有地雷，将周围全部展开
        for(int k = 0; k < 8; k++)
        {
            board[i][j] = 'B';  // 周围没有地雷，需要标记成 B
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E')
            {
                bfs(board, x, y);
            }
        }
    }
};

// 题目7：https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/description/

class Solution {
    vector<vector<bool>> visit;
    int ret;    // 统计总共需要整理的格子数量

    // (x, y+1) (x+1, y)    右/下两个方位
    int dx[2] = { 0, 1 };
    int dy[2] = { 1, 0 };

    int target, row, col;

public:
    int wardrobeFinishing(int m, int n, int cnt) {
        target = cnt, row = m, col = n;
        visit = vector<vector<bool>>(m, vector<bool>(n));

        dfs(0, 0);  // 从(0，0)原点开始

        return ret;
    }

    void dfs(int i, int j)
    {
        visit[i][j] = true;
        ret++;

        for(int k = 0; k < 2; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            // 计算横纵坐标的各位数之和，考虑到 x,y 的取值最多为2位数
            int sum_x = x / 10 + x % 10, sum_y = y / 10 + y % 10;
            if(x >= 0 && x < row && y >= 0 && y < col && visit[x][y] == false && sum_x+sum_y <= target) dfs(x, y);
        }
    }
};