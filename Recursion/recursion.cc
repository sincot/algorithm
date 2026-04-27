// 第一题： https://leetcode.cn/problems/hanota-lcci/description/

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
    {
        dfs(A, B, C, A.size());
    }

    void dfs(vector<int>& x, vector<int>& y, vector<int>& z, int n)
    {
        if(n == 1) 
        {
            z.emplace_back(x.back());    // 将 x 柱子上的最后一个元素放在 z 上
            x.pop_back();   // 删除插入的元素

            return;
        }

        // 借助 z 将 x 上的 n - 1个盘子 放在 y 
        dfs(x, z, y, n - 1);
        // 将 x 上的唯一元素插入到z 中
        z.emplace_back(x.back());
        x.pop_back();   // 删除插入的元素
        // 借助 x 将 y 上的 n - 1个盘子 放在 z
        dfs(y, x, z, n - 1);
    }

    // void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
    // {
    //     C = A;
    //     return; 
    // }
};

// 第二题：https://leetcode.cn/problems/merge-two-sorted-lists/description/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 递归的出口：谁为空，就返回另一个
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        // 谁小，就链接谁
        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// 第三题：https://leetcode.cn/problems/reverse-linked-list/description/

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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            // 当前结点为空 或者 当前结点为叶子结点
            return head;     
        }

        ListNode* newhead = reverseList(head->next);    // 让 newhead 接收逆序当前结点后的链表的头结点
        head->next->next = head;        // 当前结点下一个结点的 next 指针指向当前结点
        head->next = nullptr;           // 当前结点的 next 指针指向 nullptr

        return newhead;     // 返回逆置后的头结点
    }
};

// 第四题：https://leetcode.cn/problems/swap-nodes-in-pairs/description/

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
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* tmp = swapPairs(head->next->next);
        ListNode* ret = head->next;     // 要返回的结果，新的头结点
        head->next->next = head;
        head->next = tmp;

        return ret;     // 返回新的头结点
    }
};

// 第五题：https://leetcode.cn/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        return n < 0 ? 1 / Pow(x, (-(long long)n)) : Pow(x, n);
    }

    double Pow(double x, int n)
    {
        if(n == 0) return 1;
        double tmp  = Pow(x, n / 2);
        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
    }
};