// 题目链接：https://leetcode.cn/problems/count-and-say/description/

class Solution {
public:
    string countAndSay(int n) {
        // 返回值,至少要有1
        string ret = "1";

        // 从 1 开始解释，仅需解释 n-1 次
        for(int i = 1; i < n; i++)
        {
            // 记录本次翻译的结果
            string tmp;
            // 双指针
            for(int left = 0, right = 0; right <= ret.length(); right++)
            {
                // 如果right指向的元素不等于left指向的元素
                // 说明此时 [left,right] 区间全是相同的元素
                if(ret[right] != ret[left])
                {
                    // 相同元素的个数
                    int count = right - left;
                    // 转换成字符型,也可以使用to_string函数
                    // 加上相同的元素
                    tmp += to_string(right - left) + ret[left];
                    //tmp += count + '0';
                    //tmp += ret[left];
                    // 继续向后移动确定相同元素的区间
                    left = right;
                }
            }
            // 交给返回值
            ret = tmp; 
        }

        return ret;
    }
};
