// 题目链接：https://leetcode.cn/problems/4sum/description/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 排序
        sort(nums.begin(), nums.end());

        // 返回值
        vector<vector<int>> ret;

        // 数组的长度
        int n = nums.size();

        // 定义两个指针
        int left = 0;
        int right = n - 1;
        // 固定第一个基准值

        for(int min1 = 0; min1 <= n - 4; )
        {
            // 固定第二个基准值
            for(int min2 = min1 + 1; min2 <= n - 3; )
            {
                // 定义双指针
                int left = min2 + 1;
                int right = n - 1;

                while(left < right)
                {
                    // 求 min1 min2 left right 位置的和
                    // nums[i]的取值范围很大，int类型可能不满足范围
                    long long sum = (long long)nums[min1] + nums[min2] + nums[left] + nums[right];
                    
                    // sum > target，right向前移动
                    if(sum > target){ right--; }
                    // sum < target，left向后移动
                    else if(sum < target){ left++; }
                    else
                    {
                        ret.push_back({nums[min1], nums[min2], nums[left], nums[right]});
                        // 指针将继续移动，缩小区间范围
                        left++;
                        right--;

                        // 去重 --- right，left不能越界
                        while(left < right && nums[right] == nums[right + 1])
                        {
                            right--;
                        }

                        // 去重 --- left
                        while(left < right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                    }
                }

                // 跳出循环后，更改min2基准值
                min2++;
                // min2 去重
                while(min2 <= n - 3 && nums[min2] == nums[min2 - 1])
                {
                    min2++;
                }
            }

            // 跳出循环后，更改min1基准值
            min1++;
            // min1 去重
            while(min1 <= n - 4 && nums[min1] == nums[min1 - 1])
            {
                min1++;
            }   
        }

        return ret;
    }
};
