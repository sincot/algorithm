// 题目链接：https://leetcode.cn/problems/teemo-attacking/description/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // 返回值
        int ret = 0;
        
        // 遍历,从下标1开始
        for(int i = 1; i < timeSeries.size(); i++)
        {
            if(timeSeries[i] - timeSeries[i - 1] > duration) { ret += duration; }
            else { ret += (timeSeries[i] - timeSeries[i - 1]); }
        }
        // 记得加上最后一次攻击时的中毒时长
        ret += duration;

        return ret;
    }
};
