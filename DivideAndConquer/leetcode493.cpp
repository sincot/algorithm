// 题目链接：https://leetcode.cn/problems/reverse-pairs/description/

class Solution {
public: 
    // 辅助数组
    vector<int> tmp;

    int reversePairs(vector<int>& nums) {
        // nums元素个数
        int n = nums.size();
        // 处理辅助数组tmp
        tmp.resize(n);

        return MergeSort(0, n - 1, nums);
    }

    int MergeSort(int left, int right, vector<int>& nums)
    {
        // 递归的终止条件
        if(left >= right) { return 0; }
        // 返回值
        int ret = 0;

        // 取中间点
        int mid = left + (right - left) / 2;
        // 将nums划分成两个区域 [left, mid],[mid+1, right]
        ret += MergeSort(left, mid, nums);
        ret += MergeSort(mid + 1, right, nums);

        // 计算翻转对的个数
        int cur1 = left, cur2 = mid + 1;
        
        while(cur1 <= mid && cur2 <= right)
        {
            // 降序
            // long long 类型避免2*nums[cur2]溢出
            if(nums[cur1] > (long long)2*nums[cur2]) 
            { 
                ret += right - cur2 + 1; 
                cur1++;
            }
            else { cur2++; }
        }

        // 合并两个数组
        int begin = left, end = mid;     // 左区域
        int front = mid+1, back = right; // 右区域
        // 辅助数组tmp的下标
        int i = 0;

        // 降序
        while(begin <= end && front <= back)
        {
            if(nums[begin] > nums[front]) { tmp[i++] = nums[begin++]; }
            else { tmp[i++] = nums[front++]; }
        }
        // 未处理的元素
        while(begin <= end) { tmp[i++] = nums[begin++]; }
        while(front <= back) { tmp[i++] = nums[front++]; }

        // 还原
        for(int j = left; j <= right; j++) { nums[j] = tmp[j - left]; }

        return ret;
    }
};


class Solution {
public: 
    // 辅助数组
    vector<int> tmp;

    int reversePairs(vector<int>& nums) {
        // nums元素个数
        int n = nums.size();
        // 处理辅助数组tmp
        tmp.resize(n);

        return MergeSort(0, n - 1, nums);
    }

    int MergeSort(int left, int right, vector<int>& nums)
    {
        // 递归的终止条件
        if(left >= right) { return 0; }
        // 返回值
        int ret = 0;

        // 取中间点
        int mid = left + (right - left) / 2;
        // 将nums划分成两个区域 [left, mid],[mid+1, right]
        ret += MergeSort(left, mid, nums);
        ret += MergeSort(mid + 1, right, nums);

        
        // 计算翻转对的个数
        int cur1 = left, cur2 = mid + 1;
        
        while(cur1 <= mid && cur2 <= right)
        {
            // 升序
            // 注意除的是 2.0
            if(nums[cur1]/2.0 > nums[cur2]) 
            { 
                ret += mid - cur1 + 1; 
                cur2++;
            }
            else { cur1++; }
        }

        // 合并两个数组
        int begin = left, end = mid;     // 左区域
        int front = mid+1, back = right; // 右区域
        // 辅助数组tmp的下标
        int i = 0;

        // 降序
        while(begin <= end && front <= back)
        {
            if(nums[begin] > nums[front]) { tmp[i++] = nums[front++]; }
            else { tmp[i++] = nums[begin++]; }
        }
        // 未处理的元素
        while(begin <= end) { tmp[i++] = nums[begin++]; }
        while(front <= back) { tmp[i++] = nums[front++]; }

        // 还原
        for(int j = left; j <= right; j++) { nums[j] = tmp[j - left]; }

        return ret;
    }
};
