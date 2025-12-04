// 题目链接：https://leetcode.cn/problems/max-consecutive-ones-iii/description/

// 滑动窗口
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        int count = 0;
        for(int left = 0, right = 0; right < nums.size(); right++)
        {
            //进窗口
            if(nums[right] == 0)
            {
                count++;
            }
            
            // 判断 出窗口
            while(count > k)
            {
                if(nums[left++] == 0)
                {
                    count--;
                }
            }

            // 更新数据
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};

