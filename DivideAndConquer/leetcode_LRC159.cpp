// 题目链接：https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/description/

class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        // 生成随机数种子
        srand(time(NULL));
        // qsort不是将数组排序，而是将前k小的元素移动到前面
        qsort(0, stock.size()-1, cnt, stock);
        // 如此仅需取前k个数组作为返回值即可
        return {stock.begin(), stock.begin() + cnt};
    }

    void qsort(int begin, int end, int k, vector<int>& nums)
    {
        // 递归结束的条件
        if(begin >= end) { return; }

        // 随机生成基准值
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

        // 统计区间中元素的个数
        // [begin, left],[left+1, right-1],[right, end]
        int numleft = left - begin + 1;
        int nummid = (right-1) - (left+1) + 1;
        // 若numleft大于k，则说明前k个最小的元素在[begin, left]区间
        if(numleft >= k) { qsort(begin, left, k, nums); } // 在[begin, left]区间中找 
        // 若不满足前面的条件，满足numleft+nummid大于k
        // 则说明第k小的元素在[left+1, right-1]区间里
        // 那么它的左边部分就是前k个最小的元素
        else if(numleft + nummid >= k) { return; }
        // 若不满足前面的条件
        // 则说明第k小的元素在[right, end]区间中
        // 在[right, end]区间中找的不是第K小的元素，而是第k-numleft-nummid小的元素
        else { qsort(right, end, k-numleft-nummid, nums); }
    }
};
