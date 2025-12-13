// 题目链接：https://leetcode.cn/problems/reorder-list/description/

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
    void reorderList(ListNode* head) {
        // 处理特殊情况
        // 链表为空/链表只有一个结点，链表只有两个结点
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) { return; }
        // 1. 找到链表的中间结点
        // 定义快慢指针
        ListNode* slow = head, * fast = head;
        // 循环条件 fast/fast->next不为空
        while(fast && fast->next)
        {
            // 慢指针走一步
            slow = slow->next;
            // 快指针走两部
            fast = fast->next->next;
        }
        
        // 2. 使用头插法逆序 —— 从 slow指针指向的下一个位置开始逆序
        // 创建虚拟头结点
        ListNode* newhead = new ListNode(0);
        // 遍历后一个链表
        ListNode* pcur = slow->next;
        // 将前后两个链表断开，slow 指向的next为空
        slow->next = nullptr;
        while(pcur)
        {
            // 避免头插时丢失下一个结点的地址
            ListNode* next = pcur->next;
            //  newnode pcur newnode->next;
            pcur->next = newhead->next;
            newhead->next = pcur;
            // pcur 向后移动
            pcur = next;
        }

        // 3. 合并两个链表,使用双指针
        // 创建一个虚拟头结点
        ListNode* ret = new ListNode(0);
        // 合并时是尾插
        ListNode* ptail  = ret;
        // 遍历
        ListNode* cur1 = head;
        ListNode* cur2 = newhead->next; // newhead是虚拟头结点不参与合并
        // 无论什么情况下，cur1遍历的链表是最长的
        while(cur1 != nullptr)
        {
            // 合并
            ptail->next = cur1;
            cur1 = cur1->next;
            ptail = ptail->next;
            
            // 判断第二个链表的是否为空
            if(cur2 != nullptr)
            {
                ptail->next = cur2;
                cur2 = cur2->next;
                ptail = ptail->next;
            }
        }
    
        // 释放申请的资源
        delete newhead, ret;
    }
};
