// 题目1：https://leetcode.cn/problems/valid-sudoku/description/

class Solution {
    bool Checkrow[9][10];       // 检查行
    bool Checkcol[9][10];       // 检查列
    bool Checkgrid[3][3][10];   // 检查3*3

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 遍历原始数组
        for(int i = 0; i < board[0].size(); i++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                if(board[i][j] == '.') continue;    // 判断是否是数字

                int num = board[i][j] - '0';
                if(Checkrow[i][num] || Checkcol[j][num] || Checkgrid[i/3][j/3][num]) return false;
                // 更新状态
                Checkrow[i][num] = true;
                Checkcol[j][num] = true;
                Checkgrid[i/3][j/3][num] = true;
            }
        }

        return true;
    }
};

// 题目2：https://leetcode.cn/problems/sudoku-solver/description/

class Solution {
    bool Checkrow[9][10];
    bool Checkcol[9][10];
    bool Checkgrid[3][3][10];

public:
    void solveSudoku(vector<vector<char>>& board) {
        // 初始化全局变量
        for(int i = 0; i < board[0].size(); i++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                if(board[i][j] == '.') continue;    // 判断是否是数字

                int num = board[i][j] - '0';
                // 更新状态
                Checkrow[i][num] = true;
                Checkcol[j][num] = true;
                Checkgrid[i/3][j/3][num] = true;
            }
        }

        dfs(board);
    }

    bool dfs(vector<vector<char>>& board)
    {
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board.size(); col++)
            {
                if(board[row][col] == '.')  // 开始选择数字填充
                {
                    for(int k = 1; k <= 9; k++)
                    {   
                        // 满足其中一条，该数字 k 就不能使用(剪枝)
                        if(Checkrow[row][k] || Checkcol[col][k] || Checkgrid[row/3][col/3][k]) continue;
                        // 说明可以使用该 k 值
                        board[row][col] = k + '0';
                        Checkrow[row][k] = Checkcol[col][k] = Checkgrid[row/3][col/3][k] = true;
                        // 向下递归
                        if(dfs(board) == true) return true;
                        // 恢复现场
                        board[row][col] = '.';
                        Checkrow[row][k] = Checkcol[col][k] = Checkgrid[row/3][col/3][k] = false;
                    }

                    // 1 ~ 9 都比较完毕了，都没有返回true，此时说明该分支不行，返回false
                    return false;
                }
            }
        }

        return true;
    }
};

// 题目3：https://leetcode.cn/problems/word-search/description/

class Solution {
    bool check[7][7];
    int m, n;

public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        m = board.size(), n = board[0].size();
        
        // 找起始位置
        for(int i = 0; i < m; i++)   // 行
        {
            for(int j = 0; j < n; j++) // 列
            {
                if(board[i][j] == word[0])  // 找到起点了
                {
                    check[i][j] = true;
                    if(dfs(board, i, j, word, 1)) return true;
                    check[i][j] = false;
                }
            }   
        }

        return false;
    }

    // 采用向量的方式来区分上下左右位置
    // (x-1, y) (x+1, y) (x, y-1) (x, y+1)
    int dx[4] = { -1, +1, 0, 0 };
    int dy[4] = { 0, 0, -1, +1 };

    // x,y 表示的是起始位置的横纵坐标
    bool dfs(vector<vector<char>>& board, int x, int y, string& word, int pos)
    {
        if(pos == word.length()) return true;

        // 根据for循环就可以表示上下左右四个位置了
        for(int k = 0; k < 4; k++)
        {
            int i = x + dx[k], j = y + dy[k];
            // 下标没有越界，并且选中的位置没有被使用，并且 board[i][j] == word[pos]
            if(i >= 0 && i < m && j >= 0 && j < n && check[i][j] == false && board[i][j] == word[pos])
            {
                check[i][j] = true;
                if(dfs(board, i, j, word, pos+1)) return true;  // 判断是否合格
                check[i][j] = false;
            }
        }

        return false;
    }
};