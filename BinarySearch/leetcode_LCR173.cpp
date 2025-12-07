// 题目链接：https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/description/

class Solution {
public:
    int takeAttendance(vector<int>& records) {
        // 定义两个指针
        int left = 0, right = records.size() - 1;
        // records 中最后一个元素的下标
        int n = records.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            // 若 records[mid] == mid,left = mid + 1
            if(records[mid] == mid) { left = mid + 1; }
            // 若 records[mid] != mid,right = mid
            else { right = mid; }
        }

        // 考虑records = [0,1,2,3] 的情况
        return records[n] == n ? n+1 : left;
    }
};
