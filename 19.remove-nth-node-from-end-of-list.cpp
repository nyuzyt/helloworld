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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int length = 0;
        int tmpIndex = 0;
        while (tmp) {
            length++;
            tmp = tmp->next;
        }
        if (length == n) {
            head = head->next;
            return head;
        }
        tmpIndex = length - n;
        length = 0;
        tmp = head;
        while (length < tmpIndex - 1) {
            tmp = tmp->next;
            length++;
        }
        if (n == 1)
            tmp->next = NULL;
        else
            tmp->next = tmp->next->next;
        return head;
    }
};
