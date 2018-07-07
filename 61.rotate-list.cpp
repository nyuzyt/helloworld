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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        ListNode* tmp = head;
        int length = 0;
        while (tmp->next) {
            tmp = tmp->next;
            length++;
        }
        length++;
        tmp->next = head;
        tmp = head;
        k = length - k % length;
        int count = 0;
        while (count < k) {
            tmp = tmp->next;
            count++;
        }
        head = tmp;
        while (tmp->next != head)
            tmp = tmp->next;
        tmp->next = NULL;
        return head;
    }
};
