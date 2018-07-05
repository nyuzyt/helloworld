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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode* p = head;
        ListNode* q = p->next;
        ListNode* r = q;
        while (p && q) {
            if (!q->next)
                break;
            p->next = q->next;
            p = p->next;
            if (!p->next)
                break;
            q->next = p->next;
            q = q->next;
        }
        p->next = r;
        q->next = NULL;
        return head;
    }
};
