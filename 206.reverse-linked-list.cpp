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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* p = head;
        ListNode* q;
        while (p->next) {
            q = p->next;
            p->next = q->next;
            q->next = head;
            head = q;
        }
        return q;
    }
};
