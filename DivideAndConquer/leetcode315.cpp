// 题目链接：https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/

class Solution {
public:
    // 返回值
    vector<int> count;
    // 辅助数组
    vector<pair<int, int>> tmp;

    vector<int> countSmaller(vector<int>& nums) {
        // nums中元素的个数
        int n = nums.size();
        // 处理count
        count.resize(n);
        // 一定要处理tmp辅助数组
        tmp.resize(n);

        // 将nums中的元素与其下标一起绑定
        // <int, int> -> <nums[i], i>
        // first->nums[i] second->i
        vector<pair<int, int>> index;
        for(int i = 0; i < n; i++)
        {
            index.push_back({nums[i], i});
        }

        // 解决问题
        MergeSort(0, n - 1, index);

        return count;
    }

    void MergeSort(int left, int right, vector<pair<int, int>>& index)
    {
        // 递归的结束条件
        if(left >= right) { return; }

        // 取中间点
        int mid = left + (right - left) / 2;
        // 将数组分成两部分 [left, mid],[mid+1, right] —— 排序
        MergeSort(left, mid, index);
        MergeSort(mid+1, right, index);

        // 处理一左一右的情况
        int begin = left, end = mid;        // 左区域
        int front = mid + 1, back = right;  // 右区域
        // 辅助数组的下标
        int i = 0;
        // 需要注意数组是降序的
        while(begin <= end && front <= back)
        {
            // first 进行比较
            if(index[begin].first > index[front].first)
            {
                // 一定要注意是 += 
                count[index[begin].second] += back - front + 1;
                tmp[i++] = index[begin++];
            }
            else { tmp[i++] = index[front++]; } 
        }

        // 未处理的元素
        while(begin <= end) { tmp[i++] = index[begin++]; }
        while(front <= back) { tmp[i++] = index[front++]; }

        // 还原
        for(int j = left; j <= right; j++) { index[j] = tmp[j - left]; }
    }
};
