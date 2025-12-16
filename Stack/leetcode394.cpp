// 题目链接：https://leetcode.cn/problems/decode-string/description/

class Solution {
public:
    string decodeString(string s) {
        // 使用数组模拟栈结构
        vector<string> strs;     // 字符串栈
        strs.push_back("");      // 处理特殊情况
        vector<int> nums;        // 数字栈

        int i = 0, n = s.length();  // 字符串的长度
        // 遍历字符串s
        while(i < n)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                // 保存提取出来的数字
                int tmp = 0;
                // 提取数字（不可能越界，后面一定还有字符串）
                while(s[i] >= '0' && s[i] <= '9') { tmp = tmp*10 + (s[i++] - '0'); }
                // 加入到数字栈中
                nums.push_back(tmp);
            }
            else if(s[i] == '[')
            {
                i++;
                string tmp;
                // 提取'['后面的字符串（不可能越界，后面一定存在']'
                while(s[i] >= 'a' && s[i] <= 'z') { tmp += s[i++]; }
                // 加入到字符串栈中
                strs.push_back(tmp);
            }
            else if(s[i] == ']')
            {
                string tmp;
                // 取两个栈的栈顶元素
                int num = nums.back();
                nums.pop_back();
                string str = strs.back();
                strs.pop_back();
                // 解码
                while(num--) { tmp += str; }
                // 将结果加入到字符串栈栈顶元素的后面
                strs.back() += tmp;
                i++;    // 向后移动,跳过']'字符
            }
            else
            {
                string tmp;
                // 提取字符（可能会越界）
                while(i < n && s[i] >= 'a' && s[i] <= 'z') { tmp += s[i++]; }
                // 将提取出来的字符串加入到字符串栈的栈顶元素的后面
                strs.back() += tmp;
            }
        }

        // 最终字符串栈的栈顶元素的就是最终结果
        return strs.back();
    }
};
