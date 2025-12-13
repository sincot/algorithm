// 题目链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/description/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 求出链表的结点的个数
        ListNode* pnums = head;
        int count = 0;
        while(pnums)
        {
            pnums = pnums->next;
            count++;
        }

        // 逆序n组
        int n = count / k;

        // 创建虚拟头结点
        ListNode* newhead = new ListNode(0);
        // 遍历链表
        ListNode* pcur = head;
        // 每次逆序的头节点
        ListNode* prev = newhead;
        // 重复n次
        while(n--)
        {
            // 逆序的长度，即执行头插的次数
            int num = k;
            // 记录下一次逆序的开头
            ListNode* tmp = pcur;
            while(num--)
            {
                // 提前保存pcur的下一个结点
                ListNode* next = pcur->next;
                // 逆序 —— 头插
                pcur->next = prev->next;
                prev->next = pcur;
                pcur = next;
            }
            // 更新下一次逆序的前驱结点
            prev = tmp;
        }
        // 链接不需要翻转的结点
        prev->next = pcur;

        ListNode* ret = newhead->next;
        delete newhead;

        return ret;
    }
};
