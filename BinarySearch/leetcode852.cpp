// 题目链接：https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 定义两个指针
        // arr 数组的第一个位置和最后一个位置一定不是峰值
        // 因此left从下标1位置开始，right从下标 n - 2 位置开始
        int left = 1, right = arr.size() - 2;

        while(left < right)
        {
            int mid = left + (right - left + 1) / 2;
            // arr[mid] > arr[mid - 1],left = mid
            if(arr[mid] > arr[mid - 1]) { left = mid; }
            // arr[mid] < arr[mid - 1]),right = mid + 1
            else { right = mid - 1; }
        }

        return left;
    }
};
