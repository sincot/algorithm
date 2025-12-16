// 题目链接：https://leetcode.cn/problems/validate-stack-sequences/description/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;  // 定义一个栈结构
        int i = 0;      // 遍历pop数组

        // 一直将push数组的元素入栈
        for(auto val : pushed)
        {
            st.push(val);      // 将push数组的元素入栈
            // 判断是否需要出栈,popped数组的元素等于栈顶的元素
            // 栈不能为空并且popped下标不能越界
            while(i < popped.size() && !st.empty() && st.top() == popped[i])
            {
                i++;
                st.pop();
            }
        }
        
        if(st.empty()) { return true; }// 若栈为空，说明出栈顺序合法

        return false;
    }
};
