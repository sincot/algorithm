// 题目链接：https://leetcode.cn/problems/hamming-distance/description/?envType=problem-list-v2&envId=bit-manipulation

class Solution {
public:
    int hammingDistance(int x, int y) {
        int arr1[32] = { 0 };
        int arr2[32] = { 0 };

        // 将 x,y 的二进制位存储起来
        for(int i = 0; i < 32; i++)
        {
            // 获取x,y的每一个二进制位
            arr1[i] = (x >> i) & 1;
            arr2[i] = (y >> i) & 1;
        }

        // 计数器
        int count = 0;
        // 比较不同
        for(int i = 0; i < 32; i++)
        {
            if(arr1[i] != arr2[i])
            {
                count++;
            }
        }

        return count;
    }
};
