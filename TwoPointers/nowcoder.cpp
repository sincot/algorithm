// 题目链接：https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b

// 暴力枚举
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        // 暴力解法 
        for(int i = 0; i < array.size(); i++)
        {
            for(int j = i; j < array.size(); j++)
            {
                if(array[i] + array[j] == sum)
                {
                    return {array[i], array[j]};
                }
            }
        }

        return {};
    }
};


// 双指针算法
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        // 定义左右两个指针
        int left = 0;
        int right = array.size() - 1;

        // 循环相加
        while(left < right)
        {
            if(array[left] + array[right] > sum){ right--; }
            else if(array[left] + array[right] < sum){ left++; }
            else{ return {array[left], array[right]}; }
        }

        return {};
    }
};
