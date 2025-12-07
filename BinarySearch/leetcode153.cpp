// 题目链接：https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/

// 以 D 点位参考点
class Solution {
public:
    int findMin(vector<int>& nums) {
        //定义 left 和 right指针
        int left = 0, right = nums.size() - 1;

        while(left < right)
        {
            以 D 点为参照点
            int mid = left + (right - left) / 2;
            // nums[mid] > nums[right],left = mid + 1
            if(nums[mid] > nums[right]) { left = mid + 1; }
            // nums[mid] <= nums[right],right = mid
            else { right = mid; }
        }

        // 返回目标值
        return nums[right];
    }
};

// 以 A 点为参考点
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 记录nums的第一个元素
        int target = nums[0];
        int n = nums.size();
        // 如果数组只有一个元素，或未旋转（升序），直接返回
        if (n == 1 || nums[n - 1] >= target) { return target; }

        // 二分查找：找第一个小于 target 的元素
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // nums[mid] < target,往左区间找
            if (nums[mid] < target) { right = mid; } 
            // nums[mid] >= target,往右区间找
            else { left = mid + 1; }
        }

        // 返回目标值
        return nums[left];
    }
};
