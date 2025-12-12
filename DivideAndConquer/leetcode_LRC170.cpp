// 题目链接：https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/

class Solution {
public:
    // 定义全局变量的辅助数组 tmp
    vector<int> tmp;

    int reversePairs(vector<int>& record) {
        // records元素的个数
        int n = record.size();
        // 处理 tmp 辅助数组
        tmp.resize(n);

        return MergeSort(0, n - 1, record);
    }

    int MergeSort(int left, int right, vector<int>& nums)
    {
        // 递归终止的条件
        if(left >= right) { return 0; }

        // 返回值
        int ret = 0;
        // 找中间点
        int mid = left + (right- left) / 2;

        // 将nums数组划分成两部分 [left, mid],[mid+1, right]
        // 统计左区间中逆序对的个数，排序左区间
        ret += MergeSort(left, mid, nums);
        // 统计右区间中逆序对的个数，排序右区间
        ret += MergeSort(mid+1, right, nums);

        // 一左一右
        // 确定左右区间的指针
        int begin = left, end = mid;
        int front = mid + 1, back = right;
        int i = 0; //辅助数组的下标索引

        while(begin <= end && front <= back)
        {
            // 升序
            // if(nums[begin] > nums[front]) 
            // { 
            //     ret += (end - begin + 1); 
            //     tmp[i++] = nums[front++];    // 小的加入
            // }
            // else { tmp[i++] = nums[begin++]; }

            // 降序
            if(nums[begin] > nums[front]) 
            { 
                ret += (back - front + 1); 
                tmp[i++] = nums[begin++];       // 大的加入
            }
            else { tmp[i++] = nums[front++]; }
        }
        // 处理剩下未遍历到的
        while(begin <= end) { tmp[i++] = nums[begin++]; }
        while(front <= back) { tmp[i++] = nums[front++]; }

        // 还原
        for(int j = left; j <= right; j++)
        {
            nums[j] = tmp[j - left];
        }

        return ret;
    }
};
