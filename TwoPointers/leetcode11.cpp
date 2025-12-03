// 题目链接：https://leetcode.cn/problems/container-with-most-water/description/ 

// 暴力枚举 
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 定义一个最大值
        int maxnum = 0;

        for(int i = 0; i < height.size(); i++)
        {
            for(int j = i + 1; j < height.size(); j ++)
            {
                // 木桶效应
                int min = height[i] < height[j] ? height[i] : height[j]; 
                if(min * (j - i) > maxnum)
                {
                    maxnum = min * (j - i);
                }
            }
        }

        return maxnum;
    }
};

// 双指针算法
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 定义两个指针
        int left = 0;
        int right = height.size() - 1;
        int maxVolume = 0;

        while(left < right)
        {
            // 取数的最小值
            int minNum = min(height[left], height[right]);
            // 计算容积大小
            int volume = minNum * (right - left);
            // 取容积中的最大值
            maxVolume = max(volume, maxVolume);
            
            // 前后指针移动
            if(height[left] < height[right]){ left++; }
            else{ right--; }
        }

        return maxVolume;
    }
};
