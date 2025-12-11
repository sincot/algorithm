// 题目链接：https://leetcode.cn/problems/minimum-number-of-frogs-croaking/description/

// 解法1：if else判断
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        // 创建hash表
        unordered_map<char, int> hash;

        for(auto e : croakOfFrogs)
        {
            if(e == 'c')
            {
                if(hash['k'] >= 1) { hash['k']--; }
                
                hash[e]++;
            }
            else if(e == 'r')
            {
                if(hash['c'] >= 1) { hash['c']--; hash[e]++; }
                else { return -1; }
            }
            else if(e == 'o')
            {
                if(hash['r'] >= 1) { hash['r']--; hash[e]++; }
                else { return -1; }
            }
            else if(e == 'a')
            {
                if(hash['o'] >= 1) { hash['o']--; hash[e]++; }
                else { return -1; }
            }
            else if(e == 'k')
            {
                if(hash['a'] >= 1) { hash['a']--; hash[e]++; }
                else { return -1; }
            }
        }

        for(auto& kv : hash)
        {
            if(kv.first != 'k' && kv.second != 0)
            {
                return -1;
            }
        }

        return hash['k'];
    }
};

// 解法2：hash映射
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        // 指出蛙鸣"croak"
        string s = "croak";
        // 蛙鸣的长度
        int n = s.length();
        // 使用数组模拟hash表
        vector<int> hash(n);

        // 存储"croak"中字符的下标，使用hash表存储
        // 存储x字符以及x字符对应的下标
        unordered_map<char, int> index;
        // 遍历蛙鸣字符串
        for(int i = 0; i < n; i++)
        {
            index[s[i]] = i;
        }

        // 遍历croakOfFrogs字符串
        for(auto ch : croakOfFrogs)
        {
            if(ch == 'c')
            {
                // 找'k'
                // 若 'k' 存在hash数组中，前驱字符--，当前字符++
                if(hash[n - 1] != 0) { hash[n - 1]--; }
                // 若 'k' 不存在hash数组中，当前字符++
                hash[0]++; 
            }
            else
            {
                // 当前字符的下标
                int i = index[ch];
                // 判断当前字符下标的前驱字符是否存在hash数组中
                // 不存在直接返回-1
                if(hash[i - 1] == 0) { return -1; }
                // 存在，前驱字符--，当前字符++
                hash[i - 1]--;
                hash[i]++;
            }
        }

        // 除了最后一个字符'k'之外，其它字符的个数为0
        for(int i = 0; i < n - 1; i++)
        {
            // 若不为0,直接返回-1
            if(hash[i] != 0) { return -1; }
        }

        // 返回hash数组中最后一个元素'k'对应的个数
        return hash[n - 1];
    }
};
