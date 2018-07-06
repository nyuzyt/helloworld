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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* p = head;
        int length = 0;
        while (p) {
            p = p->next;
            length++;
        }
        int tmpLength = (length + 1) / 2;
        int count = 0;
        p = head;
        while (count < tmpLength) {
            p = p->next;
            count++;
        }
        ListNode* curHead = p;
        while (p->next) {
            ListNode* q = p->next;
            p->next = q->next;
            q->next = curHead;
            curHead = q;
        }
        count = 0;
        while ((count < length / 2) && curHead && head) {
            if (curHead->val != head->val)
                return false;
            curHead = curHead->next;
            head = head->next;
        }
        return true;
    }
};
