// 题目链接：https://leetcode.cn/problems/merge-k-sorted-lists/description/

// 优先级队列
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
    struct Compare{ bool operator()(const ListNode* e1, const ListNode* e2){ return e1->val > e2->val; } }; // 建小堆
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {        
        // 创建优先级队列,注意优先级队列中的元素都是ListNode*结点
        // 优先级队列默认是建大根堆，若想建小根堆，传反函数参数greater
        // 由于pq中存储的是ListNode*类型，因此比较函数需要自己实现
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        // 入堆
        for(auto& e : lists)
        {
            // 空指针就不入堆了
            if(e) { pq.push(e); }
        }
        
        // 创建虚拟结点
        ListNode* newhead = new ListNode(0);
        ListNode* ptail = newhead;
        // 直到优先级队列为空，停止循环
        while(!pq.empty())
        {
            // 保存出堆的结点
            ListNode* node = pq.top();
            // 出堆顶的结点
            pq.pop();
            // 链接结点
            ptail->next = node;
            ptail = ptail->next;
            // 如果出结点的下一个结点不为空，就入堆
            if(node->next) { pq.push(node->next); }
        }

        return newhead->next;
    }
};


// 递归
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
    //struct Compare{ bool operator()(const ListNode* e1, const ListNode* e2){ return e1->val > e2->val; } }; // 建小堆
public:
    vector<ListNode*> tmp;
    ListNode* mergeKLists(vector<ListNode*>& lists) {        
        // 链表的个数
        int n = lists.size();
        // 处理辅助数组tmp
        tmp.resize(n);
        // 合并从0到n-1的链表
        return MergeSort(0, n-1, lists);
    }

    ListNode* MergeSort(int left, int right, vector<ListNode*>& lists)
    {
        // 递归的终止条件
        if(left > right) { return nullptr; }
        // 只有一个链表，不用合并
        if(left == right) { return lists[left]; }

        // 取中间点
        int mid = left + (right - left) / 2;
        // 将链表分成两个区域[left, mid],[mid+1, right]
        ListNode* head1 = MergeSort(left, mid, lists);
        ListNode* head2 = MergeSort(mid+1, right, lists);

        // 合并
        ListNode* newhead = new ListNode(0);
        ListNode* ptail = newhead;
        ListNode* cur1 = head1, *cur2 = head2;
        // cur1和cur2不为空时，合并
        while(cur1 && cur2)
        {
            if(cur1->val < cur2->val)
            {
                ptail->next = cur1;
                cur1 = cur1->next;
                ptail = ptail->next;
            }
            else
            {
                ptail->next = cur2;
                cur2 = cur2->next;
                ptail = ptail->next;
            }
        }

        // 未合并的
        if(cur1) { ptail->next = cur1; }
        if(cur2) { ptail->next = cur2; }

        ptail = newhead->next;
        delete newhead;

        return ptail;
    }
};
