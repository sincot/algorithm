// 题目1：https://leetcode.cn/problems/letter-case-permutation/description/

class Solution {
    vector<string> ret;
    string path;

public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);

        return ret;
    }

    void dfs(string s, int pos)
    {
        if(path.length() == s.length())
        {
            ret.emplace_back(path);
            return;
        }

        // 选择当前的字母
        path.push_back(s[pos]);
        dfs(s, pos + 1);
        path.pop_back();

        if(isalpha(s[pos]))   // 如果是英文字母,才会面临变/不变的选择
        {
            // 选择转化后的字母
            // 是大写字母，转成小写字母并插入；是小写字母，转成大写字母并插入
            path.push_back(isupper(s[pos]) ? tolower(s[pos]) : toupper(s[pos]));
            dfs(s, pos + 1);
            path.pop_back();
        }
    }
};

// 题目2：https://leetcode.cn/problems/beautiful-arrangement/description/

class Solution {
    int ret = 0;
    vector<int> path;
    bool check[16];

public:
    int countArrangement(int n) {
        dfs(n);

        return ret;
    }

    void dfs(int n)
    {
        if(path.size() == n)
        {
            ret++;
            return;
        }

        int pos = path.size() + 1;  // 当前要填的位置（第几个位置）

        // 生成 1~n 的数
        for(int i = 1; i < n + 1; i++)
        {
            if(check[i] == false)   // 没被使用
            {
                // 判断是否满足优美排列的定义
                if((pos % i == 0) || (i % pos == 0))    // 满足其中任意一种，就是优美排列
                {
                    path.emplace_back(i);   // 插入
                    check[i] = true;        // 被使用了
                    dfs(n);     // 是优美排列，就向下递归
                    path.pop_back();
                    check[i] = false;
                }
            }
        }
    }
};


// 题目3：https://leetcode.cn/problems/n-queens/description/

class Solution {
    vector<vector<string>> ret;
    vector<string> path;

    // 三个数组
    bool Checkcol[10];         // 记录每列是否存在皇后
    bool Checkdigit1[20];    // 记录主对角线上是否存在皇后
    bool Checkdigit2[20];    // 记录副对角线上是否存在皇后 

public:
    vector<vector<string>> solveNQueens(int n) {
        // 初始化 path
        path.resize(n);
        for(int i = 0; i < n; i++)
            path[i].append(n, '.');
    
        dfs(n, 0);

        return ret;
    }

    void dfs(int n, int row)   // 有几行
    {
        if(row == n)    // 到达最后一行了，说明放置完毕
        {
            ret.emplace_back(path);
            return;
        }

        // 行固定了，选择第几列
        for(int col = 0; col < n; col++)
        {
            // 判断选择的位置是否可以放置
            // 选择的列上不存在皇后，选择的主对角线上没有皇后(y-x+n = b+n)，选择的副对角线上没有皇后(y+x = b)
            // 满足这三个条件，那么该位置就可以放置皇后
            if(Checkcol[col] == false && Checkdigit1[row-col+n] == false && Checkdigit2[row+col] == false)
            {
                path[row][col] = 'Q';
                // 表示这一行，这一主/副对角线已经被使用过了
                Checkcol[col] = true;
                Checkdigit1[row-col+n] = true;
                Checkdigit2[row+col] = true;

                // 向下递归
                dfs(n, row + 1);

                // 恢复现场
                path[row][col] = '.';
                Checkcol[col] = false;
                Checkdigit1[row-col+n] = false;
                Checkdigit2[row+col] = false;
            }
        }
    }
};