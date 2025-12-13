// 题目链接：https://leetcode.cn/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 创建一个虚拟头结点
        ListNode* newhead = new ListNode(0);
        // 返回链表的尾指针
        ListNode* ptail = newhead;
        // 遍历两个链表
        ListNode* cur1 = l1, *cur2 = l2;
        // 记录两数之和
        int sum = 0;

        // 当两个链表都不为空时，相加停止，或者sum不为0时
        // 为什么要考虑sum不为0时呢？因为sun中可能存着进位
        // 如 24 + 965,5与1,6与4,进位1,9+1,进位1,此时cur1和cur2都已经为空,但是还有一个进位
        while(cur1 || cur2 || sum)
        {
            // 加第一个链表,链表不能为空
            if(cur1)
            {
                sum += cur1->val;
                // cur1 向后移动
                cur1 = cur1->next;
            }
            // 加上第二个链表
            if(cur2)
            {
                sum += cur2->val;
                // cur2 向后移动
                cur2 = cur2->next;
            }

            // 新建结点
            ptail->next = new ListNode(sum % 10);
            // 尾指针更新
            ptail = ptail->next;
            // 进位
            sum /= 10;
        }
        // 释放申请的资源
        ptail = newhead->next;
        delete newhead;

        return ptail;
    }
};
