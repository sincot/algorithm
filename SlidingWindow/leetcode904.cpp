// 题目链接：https://leetcode.cn/problems/fruit-into-baskets/description/

// 滑动窗口
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // 统计窗口内出现了多少种水果
        unordered_map<int, int> hash;

        // 返回值
        int ret = 0;
        for(int left = 0, right = 0; right < fruits.size(); right++)
        {
            // 进窗口，将right指向的元素插入到hash
            hash[fruits[right]]++;

            // 判断
            while(hash.size() > 2)
            {
                // 出窗口
                // 减少left指向位置的元素个数
                hash[fruits[left]]--;

                // 判断hash表中，left指向的位置的元素个数等于0
                if(hash[fruits[left]] == 0)
                {
                    hash.erase(fruits[left]);
                }

                // left向后移动
                left++;
            }

            // 更新
            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};
