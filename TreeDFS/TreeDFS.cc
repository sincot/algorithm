// 第一题：https://leetcode.cn/problems/evaluate-boolean-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left == nullptr) return root->val == 0 ? false : true;     // 递归的出口：遇到叶子节点

        bool left = evaluateTree(root->left);       // 获取左子树的运算结果
        bool right = evaluateTree(root->right);     // 获取右子树的运算结果
        return root->val == 2 ? left | right : left & right;    // 2 —— OR；3 —— AND
    }
};

// 第二题：https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int presum)
    {
        // 1. 计算前驱和
        if(root != nullptr) presum = root->val + presum * 10;           // 前驱和
        // 2. 递归出口
        if(root->left == nullptr && root->right == nullptr)   return presum;
        int ret = 0;
        // 3. 将前驱和分别传递给左右子树
        if(root->left) ret += dfs(root->left, presum);
        if(root->right) ret += dfs(root->right, presum);
        // 4. 返回计算得到的和 
        return ret;
    }
};

// 第三题：https://leetcode.cn/problems/binary-tree-pruning/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        // 1. 递归的出口
        if(root == nullptr) return nullptr;
        // 2. 处理左子树
        root->left = pruneTree(root->left);
        // 3. 处理右子树
        root->right = pruneTree(root->right);
        // 4. 判断 —— 左右子树都为空，并且当前结点的val值为0
        if(root->val == 0 && root->left == nullptr && root->right == nullptr) return nullptr;

        // 返回自己
        return root;
    }
};

// 第四题：https://leetcode.cn/problems/validate-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long prev = LLONG_MIN;     // 定义一个全局变量
    bool isValidBST(TreeNode* root) {
        // 递归出口
        if(root == nullptr) return true;

        // 中序遍历
        bool left = isValidBST(root->left);         // 左
        if(left == false) return false;

        if(root->val > prev) { prev = root->val; }  // 根
        else return false;

        bool right = isValidBST(root->right);       // 右
        if(right == false) return false;

        return true;
    }
};

// 第五题：https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;  // 计数器
    int ret = 0;    // 第 K 小的元素

    int kthSmallest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return ret;
    }

    void dfs(TreeNode* root)
    {
        if(root == nullptr || count == 0) return;

        // 中序遍历
        dfs(root->left);
        count--;
        if(count == 0) ret = root->val;
        dfs(root->right);
    }
};

// 第六题：https://leetcode.cn/problems/binary-tree-paths/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<string> ret;     // 定义全局变量，用于存储路径
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        dfs(root, path);

        return ret;
    }

    void dfs(TreeNode* root, string path)   // 千万不要使用引用，不然path就变成全局变量了
    {
        if(root == nullptr) return;     // 递归出口
        path += to_string(root->val);   // 无论是叶子结点还是非叶子节点，都会执行这一操作
        if(root->left == nullptr && root->right == nullptr)     // 遇到叶子结点
        {
            ret.emplace_back(path);
            return;
        }
        path += "->";

        if(root->left) dfs(root->left, path);  // 左
        if(root->right) dfs(root->right, path); // 右
    }
};

// 第七题：https://leetcode.cn/problems/permutations/description/

class Solution {
    vector<vector<int>> ret;     // 记录结果
    vector<int> path;            // 记录路径
    bool check[7];               // 1 <= nums.length <= 6

public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);

        return ret;
    }

    void dfs(vector<int>& nums)
    {
        if(path.size() == nums.size()) // 遇到叶子节点，直接添加结果
        {
            ret.emplace_back(path);      
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(check[i] == false)   // 判断当前的数是否被使用了，false —— 没有，true —— 有
            {
                path.emplace_back(nums[i]);     
                check[i] = true;    // 被使用了
                dfs(nums);  // 进入下一层

                // 递归出来后，完成回溯的操作，恢复现场
                path.pop_back();    // 移除 path 数组最后一个元素
                check[i] = false;   // 没被使用
            }
        }
    }
};

// 第八题：https://leetcode.cn/problems/subsets/description/

class Solution {
    vector<vector<int>> ret;
    vector<int> path;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);

        return ret;
    }

    void dfs(vector<int>& nums, int pos)
    {
        if(pos == nums.size())      // 遇到叶子节点,就将结果添加到 ret 二维数组中
        {
            ret.emplace_back(path);
            return;
        }

        // 选择
        path.emplace_back(nums[pos]);
        dfs(nums, pos+1);
        path.pop_back();    // 从下一层返回之后，恢复现场

        // 不选
        dfs(nums, pos+1);
    }
};