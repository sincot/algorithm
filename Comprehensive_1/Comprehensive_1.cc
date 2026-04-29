// 题目1：https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/

class Solution {
    int path;   // 记录路径
    int ret = 0;    // 记录计算结果
public:
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0);

        return ret;
    }

    int dfs(vector<int>& nums, int pos)
    {
        for(int i = pos; i < nums.size(); i++)
        {
            path ^= nums[i];    // 将路径上数全部异或在一起
            dfs(nums, i + 1);   // 向下递归
            path ^= nums[i];    // 恢复现场，再次异或上添加的值，就可以将其从path中移除
        }
        
        return ret += path;     // 加上 path 路径异或的结果
    }
};

// 题目2：https://leetcode.cn/problems/permutations-ii/description/

class Solution {
    vector<vector<int>> ret;    // 记录返回的结果
    vector<int> path;           // 记录路径
    bool check[9];              // 检查路径上数是否被使用

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums);

        return ret;
    }

    void dfs(vector<int>& nums)
    {
        if(path.size() == nums.size()) 
        {
            ret.emplace_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            // 只关心 "不合法" 的分支
            // if(check[i] == true || (i != 0 && nums[i] == nums[i - 1] && check[i - 1] == false)) // 剪枝
            //     continue;
            
            // path.emplace_back(nums[i]);
            // check[i] = true;    // 被使用了
            // dfs(nums, pos + 1);
            // path.pop_back();
            // check[i] = false;    // 没被使用

            // 只关心 "合法" 的分支
            if(check[i] == false && (i == 0 || nums[i] != nums[i - 1] || check[i - 1] == true)) // 剪枝
            {
                path.emplace_back(nums[i]);
                check[i] = true;    // 被使用了
                dfs(nums);
                path.pop_back();
                check[i] = false;    // 没被使用
            }
        }
    }
};

// 题目3：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/

class Solution {
    unordered_map<char, string> phone = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    string path;            // 记录路径
    vector<string> ret;     // 记录返回

public:
    vector<string> letterCombinations(string digits) {
        dfs(digits, 0);     // 字符串

        return ret;
    }

    void dfs(string digits, int pos)
    {
        if(pos == digits.length())
        {
            ret.emplace_back(path);
            return;
        }

        // 记录当前是数字所对应的字符
        string number = phone[digits[pos]];
        for(auto& e : number)
        {
            path.push_back(e);      // 选择一个直接插入，不需要判断是否被使用
            dfs(digits, pos + 1);
            path.pop_back();        // 递归出来之后，将插入的数据给移除
        }
    }
};

// 题目4：https://leetcode.cn/problems/generate-parentheses/description/

class Solution {
    vector<string> ret;     // 记录返回结果
    string path;            // 记录路径
    string str = "()";
    int left;               // path 路径中左括号的个数
    int right;              // path 路径中右括号的个数

public:
    vector<string> generateParenthesis(int n) {
        dfs(n);

        return ret;
    }

    void dfs(int n)
    {
        if(path.length() == 2*n)
        {
            ret.emplace_back(path);
            return;
        }

        if(left < n)    // 左括号数量小于 n ，可以添加左括号
        {
            path += str[0];
            left++;
            dfs(n);
            path.pop_back();
            left--;
        }

        if(right < left)    // 右括号的数量小于左括号，可以添加右括号
        {
            path += str[1];
            right++;
            dfs(n);
            path.pop_back();
            right--;
        }
    }
};

// 题目5：https://leetcode.cn/problems/combinations/description/

class Solution {
    vector<vector<int>> ret;
    vector<int> path;

public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);

        return ret;
    }

    // pos 表示从哪个数开始枚举
    void dfs(int n, int k, int pos)
    {
        if(path.size() == k)
        {
            ret.emplace_back(path);
            return;
        }

        for(int i = pos; i < n + 1; i++)
        {
            path.emplace_back(i);
            dfs(n, k, i + 1);   // 从当前数的下一个数开始
            path.pop_back();
        }
    }
};

// 题目6：https://leetcode.cn/problems/target-sum/description/

class Solution {
    int count = 0;  // 返回值
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;    // 记录路径和
        dfs(nums, target, sum, 0);

        return count;
    }

    // 既然是非负整数数组，那么正整数选择正号相当于没有选
    // 因此题目转化成了选择负号还是不选
    void dfs(vector<int>& nums, int target, int sum, int pos)
    {
        if(pos == nums.size() && sum == target) count++;
        if(pos == nums.size()) return;      // 递归出口

        // 选择负号
        dfs(nums, target, sum + -nums[pos], pos+1);

        // 不选择负号
        dfs(nums, target, sum + nums[pos], pos+1);
    }
};

// 题目7：https://leetcode.cn/problems/combination-sum/description/

class Solution {
    vector<vector<int>> ret;
    vector<int> path;   // 记录路径
    int sum;            // 记录路径和

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);

        return ret;
    }

    void dfs(vector<int>& candidates, int target, int pos)
    {
        if(sum == target)
        {
            ret.emplace_back(path);
            return;
        }

        // pos 就是为了去除重复的子集
        for(int i = pos; i < candidates.size(); i++)
        {
            if(sum < target)    // 剪枝
            {
                path.emplace_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates, target, i);
                path.pop_back();
                sum -= candidates[i];
            }
            else return;    // 大于 target，直接返回
        }
    }
};