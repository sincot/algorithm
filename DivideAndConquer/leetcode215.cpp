// 题目链接：https://leetcode.cn/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 生成随机数种子
        srand(time(NULL));

        return qsort(0, nums.size() - 1, k, nums);;
    }

    // 排序
    int qsort(int begin, int end, int k, vector<int>& nums)
    {
        // 当区间只有一个元素，直接返回这个元素
        if(begin == end) { return nums[begin]; }
        // 为什么不考虑 begin > end,即区间不存在的情况
        // 接下来的判断条件会保证只要进入了qsort函数区间一定存在

        // 随机数确定基准值
        int key = nums[rand() % (end - begin + 1) + begin];
        // 三个指针
        int left = begin - 1, cur = begin, right = end + 1;

        // 划分
        while(cur < right)
        {
            if(nums[cur] < key) { swap(nums[++left], nums[cur++]); }
            else if(nums[cur] > key) { swap(nums[--right], nums[cur]); }
            else { cur++; }
        }

        // [begin, left],[left+1, right-1],[right, end]
        // 统计区间中的元素个数
        int numleft = left - begin + 1;
        int nummid = (right-1) - (left+1) + 1;
        int numright = end - right + 1;

        // 落在[right, end]区间中
        if(numright >= k)
        {
            //在[right, end]中找第K大的元素
            return qsort(right, end, k, nums);
        }
        // 落在[left+1, right-1]区间中
        else if(nummid + numright >= k)
        {
            // 直接返回基准值
            return key;
        }
        // 落在[begin, left]区间中
        else
        {
            // 在[begin, left]中找第K - nummid - numright 大的元素
            return qsort(begin, left, k-nummid-numright, nums);
        }
    }
};
