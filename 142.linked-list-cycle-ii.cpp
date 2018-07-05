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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        if (!head)
            return NULL;
        else
            while (slow->next && fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (fast == slow) {
                    ListNode* tmp = head;
                    while (slow != tmp) {
                        slow = slow->next;
                        tmp = tmp->next;
                    }
                    return slow;
                }
            }
        return NULL;
    }
};
