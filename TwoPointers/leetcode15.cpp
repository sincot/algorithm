// 题目链接：https://leetcode.cn/problems/3sum/description/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 返回值
        vector<vector<int>> ret;

        // 排序
        sort(nums.begin(), nums.end());
        // 序列的大小
        int n = nums.size();
        // 固定基准值 --- ++操作放到循环中取处理，为了进行去重操作
        for(int min = 0; min < n; )
        {
            // 基准值仅需 <= 0 即可
            if(nums[min] > 0)
            {
                break;
            }

            // 定义两个指针
            int left = min + 1;
            int right = n - 1;

            while(left < right)
            {
                int sum = nums[left] + nums[right] + nums[min];

                if(sum > 0) { right--; }
                else if(sum < 0) { left++; }
                else
                {
                    ret.push_back({nums[min], nums[left], nums[right]});
                    // 指针不要停，缩小区间，继续查找
                    left++;
                    right--;
                    //去重 --- left
                    // left < right 是为了避免 left 越界
                    while(left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    // 去重 --- right
                    // left < right 是为了避免 right 越界
                    while(left < right && nums[right] == nums[right + 1]) 
                    {
                        right--;
                    }
                }
            }

            // 先让 min++,方便完成去重操作
            min++;
            // 去重 --- min
            // min < n 是为了避免 min 越界
            while(min < n && nums[min] == nums[min - 1]) 
            {
                min++;
            }
        }

        return ret;
    }
};
