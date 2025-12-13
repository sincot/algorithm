// 题目链接：https://leetcode.cn/problems/swap-nodes-in-pairs/description/

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
    ListNode* swapPairs(ListNode* head) {
        // 创建一个虚拟头结点
        ListNode* newhead = new ListNode(0);
        // 与原链表链接起来
        newhead->next = head;

        // 定义变量
        ListNode* prev = newhead;
        ListNode* cur = prev->next;
        ListNode* next = NULL;
        ListNode* nnext = NULL;
        if(cur != NULL)  { next = cur->next; }
        if(next != NULL) { nnext = next->next; }

        // 循环终止的条件,cur为空/next为空
        // NULL->1->2->3->4
        while(cur && next)
        {
            // 交换
            prev->next = next;
            // 能进入到循环中,就能够说明next不为空
            // 因此不需要判断next是否为空
            next->next = cur;
            cur->next = nnext;

            // 修改指针
            prev = cur;         // 指针移动,prev移动到cur处
            cur = prev->next;
            if(cur != NULL) { next = cur->next; }
            if(next != NULL) { nnext = next->next; }
        }

        return newhead->next;
    }
};
