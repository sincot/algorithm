// 题目1：https://leetcode.cn/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        // 1. 创建 dp 表
        vector<int> dp(n);

        // 2. 初始化
        dp[0] = nums[0];

        // 3. 填表
        int sum = dp[0];    // 记录 dp 表中的最大值
        for(int i = 1; i < n; i++)
        {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            sum = max(sum, dp[i]);
        }

        // 4. 返回值 —— 返回 dp 表中最大的元素
        return sum;
    }
};

// 题目2：https://leetcode.cn/problems/maximum-sum-circular-subarray/description/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int n = nums.size();
        // 1. 创建 f.g 两张 dp 表
        vector<int> f(n), g(n);

        // 2. 初始化
        f[0] = g[0] = nums[0];

        // 3. 填表
        int sum = nums[0], f_max = f[0], g_min = g[0];
        for(int i = 1; i < n; i++)
        {
            sum += nums[i];
            f[i] = max(nums[i], f[i-1] + nums[i]);
            g[i] = min(nums[i], g[i-1] + nums[i]);
            f_max = max(f_max, f[i]), g_min = min(g_min, g[i]);
        }

        // 4. 返回值
        return g_min == sum ? f_max : max(f_max, sum - g_min);
    }
};

// 题目3：https://leetcode.cn/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        // 1. 创建 f,g 两张 dp 表
        vector<int> f(n), g(n);

        // 2. 初始化
        f[0] = g[0] = nums[0];

        // 3. 填表
        int ret = f[0];    // 记录 f 表中值最大的
        for(int i = 1; i < n; i++)
        {
            f[i] = max(nums[i], nums[i] >= 0 ? nums[i] * f[i-1] : nums[i] * g[i - 1]);
            g[i] = min(nums[i], nums[i] >= 0 ? nums[i] * g[i-1] : nums[i] * f[i - 1]);
            ret = max(ret, f[i]);
        }

        // 4. 返回值
        return ret;
    }
};

// 题目4：https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/description/

class Solution {
public:
    int getMaxLen(vector<int>& nums)
    {
        int n = nums.size();
        // 1. 创建 f,g 两张 dp 表
        vector<int> f(n+1), g(n+1);

        // 2. 初始化 —— 在建表的时候就已经完成

        // 3. 填表
        int ret = 0;
        for(int i = 1; i <= n; i++)
        {
            if(nums[i - 1] > 0)
            { 
                f[i] = f[i - 1] + 1; 
                g[i] = (g[i - 1] == 0 ? 0 : g[i - 1] + 1); 
            }
            if(nums[i - 1] < 0)
            { 
                f[i] = (g[i - 1] == 0 ? 0 : g[i - 1] + 1); 
                g[i] = f[i - 1] + 1;
            }
            ret = max(ret, f[i]);
        }

        // 4. 返回值
        return ret;
    }
};

// 题目5：https://leetcode.cn/problems/arithmetic-slices/description/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // 细节处理
        if(n == 1 || n == 2) return 0;
        // 1. 创建 dp 表
        vector<int> dp(n);

        // 2. 初始化 —— 在创建 dp 表时，就已经初始化完毕

        // 3. 填表
        int sum = 0;
        for(int i = 2; i < n; i++)
        {
            dp[i] = nums[i] - nums[i-1] == nums[i-1] - nums[i-2] ? dp[i - 1] + 1 : 0;
            sum += dp[i];
        }

        // 4. 返回值
        return sum;
    }
};

// 题目6：https://leetcode.cn/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr)
    {
        int n = arr.size();
        // 1. 创建 f,g 两张 dp 表
        vector<int> f(n, 1), g(n, 1);

        // 2. 初始化 —— 在建表时，就已经初始化完毕

        // 3. 填表
        int ret = max(f[0], g[0]);
        for(int i = 1; i < n; i++)
        {
            if(arr[i-1] > arr[i]) { g[i] = f[i-1] + 1;  ret = max(ret, g[i]); }
            if(arr[i-1] < arr[i]) { f[i] = g[i-1] + 1;  ret = max(ret, f[i]); }
        }

        // 4. 返回值
        return ret;
    }
};

// 题目7：https://leetcode.cn/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        // 将字典中的单词填写到 hash 表中
        unordered_set<string> hash;
        for(auto& e : wordDict) hash.insert(e);

        s = ' ' + s;            // 使原始字符串的下标统一 +1
        int n = s.length();     // 比原字符串的长度新增了1
        // 1. 创建 dp 表
        vector<bool> dp(n);

        // 2. 初始化
        dp[0] = true;

        // 3. 填表
        for(int i = 1; i < n; i++)
        {
            for(int j = i; j >= 1; j--)     // 最后一个单词的起始位置
            {
                if(dp[j-1] && hash.count(s.substr(j, i - j + 1)))  { dp[i] = true; break; }
            }
        }

        // 4. 返回值
        return dp[n - 1];
    }
};

// 题目8：https://leetcode.cn/problems/unique-substrings-in-wraparound-string/description/

class Solution {
public:
    int findSubstringInWraproundString(string s)
    {
        int n = s.length();
        // 1. 创建 dp 表
        vector<int> dp(n, 1);

        // 2. 初始化 —— 在创建dp表时，就已经初始化完毕

        // 3. 填表
        for(int i = 1; i < n; i++)
        {
            if((s[i-1] + 1 == s[i]) || (s[i-1] == 'z' && s[i] == 'a'))  dp[i] += dp[i-1];
        }

        // 4. 返回值
        int arr[26] = { 0 }, sum = 0;
        for(int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';
            arr[index] = max(arr[index], dp[i]);
        }
        for(auto e : arr) sum += e;

        return sum;
    }
};