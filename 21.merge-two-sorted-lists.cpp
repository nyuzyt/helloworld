/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode* p = NULL;
        if (l1->val > l2->val) {
            p = l1;
            l1 = l2;
            l2 = p;
        }
        p = l1;
        ListNode* curHead1 = l1->next;
        ListNode* curHead2 = l2;
        while (curHead1 || curHead2) {
            if (!curHead1) {
                p->next = curHead2;
                p = p->next;
                curHead2 = curHead2->next;
                continue;
            }
            if (!curHead2) {
                p->next = curHead1;
                p = p->next;
                curHead1 = curHead1->next;
                continue;
            }
            if (curHead1->val < curHead2->val) {
                p->next = curHead1;
                p = p->next;
                curHead1 = curHead1->next;
            } else {
                p->next = curHead2;
                p = p->next;
                curHead2 = curHead2->next;
            }
        }
        return l1;
    }
};
