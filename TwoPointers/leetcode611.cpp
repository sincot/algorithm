// 题目链接：https://leetcode.cn/problems/valid-triangle-number/description/

// 暴力枚举
class Solution {
public:
    
    bool CmpTn(int i, int j, int k)
    {
        if((i + j > k) && (i + k > j) && (j + k > i))
        {
            return true;
        }

        return false;
    }

    int triangleNumber(vector<int>& nums) {
        // 暴力枚举
        int count = 0; // 计数器

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                for(int k = j + 1; k < nums.size(); k++)
                {
                    if(CmpTn(nums[i], nums[j], nums[k]))
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

// 双指针算法
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 排序
        sort(nums.begin(), nums.end());
        // 固定最大值
        int max = nums.size() - 1;
        // 定义计数器
        int count = 0;

        while(max >= 2)
        {
            // 将双指针定义在循环内部，方便实时更新
            int left = 0;
            int right = max - 1;

            while(left < right)
            {
                if(nums[left] + nums[right] > nums[max])
                {
                    count += right - left; // 计数
                    right--;
                }
                else
                {
                    left++;
                }
            }
            
            // 更换固定数
            max--;
        }
        
        return count;
    }
};
