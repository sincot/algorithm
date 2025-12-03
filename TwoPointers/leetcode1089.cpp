// 题目链接：https://leetcode.cn/problems/duplicate-zeros/description/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int dest = -1;
        int cur = 0;
        int n = arr.size();
        
        // 先找到最后一个复写的数
        while(cur < n)
        {
            if(arr[cur] != 0){ dest++; }
            else{ dest += 2; }
            
            if(dest >= n - 1){ break; }
            cur++;
        }
        
        // 边界处理
        if(dest == n)
        {
            arr[n - 1] = 0;
            if(dest )
            dest -= 2;
            cur--;
        }

        // 从后向前执行复写操作
        while(cur >= 0)
        {
            if(arr[cur] != 0)
            {
                arr[dest--] = arr[cur--];
            }
            else
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }
    }
};
