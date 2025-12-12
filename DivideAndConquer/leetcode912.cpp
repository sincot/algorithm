// 题目链接：https://leetcode.cn/problems/sort-an-array/description/

// 快速排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 生成随机数种子
        srand(time(NULL));
        // 快速排序
        qsort(0, nums.size() - 1, nums);
        
        return nums;
    }

    // 快速排序
    void qsort(int begin, int end, vector<int>& nums)
    {
        // 递归出口
        if(begin >= end) { return; }
        // 获得基准值key
        int key = nums[rand() % (end - begin + 1) + begin];

        // 定义三个指针
        int left = begin - 1, cur = begin, right = end + 1;

        // 划分
        while(cur < right)
        {
            if(nums[cur] < key) { swap(nums[++left], nums[cur++]); }
            else if(nums[cur] > key) { swap(nums[--right], nums[cur]); }
            else { cur++; }
        }

        // 排序 [begin, left],[left + 1， right - 1],[right, end]
        qsort(begin, left, nums);   // 左区域
        qsort(right, end, nums);    // 右区域
    }
};


// 归并排序
class Solution {
public:
    // 辅助数组定义成全局的
    vector<int> ret;

    vector<int> sortArray(vector<int>& nums) {
        // 预开辟空间,使用resize函数
        ret.resize(nums.size());
        // 归并排序
        MergeSort(0, nums.size() - 1, nums);

        return nums;
    }

    void MergeSort(int left, int right, vector<int>& nums)
    {
        // 递归的终止条件
        if(left >= right) { return; }

        // 1. 选择中间点
        // 中间值mid
        int mid = left + (right - left) / 2;

        // 2. 划分左右两个区域
        // 划分 [left, mid],[mid+1, right]
        MergeSort(left, mid, nums);
        MergeSort(mid+1, right, nums);

        // 3. 合并两个数组
        // 确定两个数组的边界
        int begin = left, end = mid;        // 遍历第一个数组
        int front = mid + 1, back = right;  // 遍历第二个数组
        // 辅助数组
        //vector<int> ret(right - left + 1);
        int i = 0;
        while(begin <= end && front <= back)
        {
            if(nums[begin] < nums[front]) { ret[i++] = nums[begin++]; }
            else { ret[i++] = nums[front++]; }
        }

        // 处理未遍历完的数组
        while(begin <= end) { ret[i++] = nums[begin++]; }
        while(front <= back) { ret[i++] = nums[front++]; }

        // 4. 还原
        for(int i = left; i <= right; i++)
        {
            nums[i] = ret[i - left];
        }
    }
};
