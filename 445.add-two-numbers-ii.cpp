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
    ListNode* reverse(ListNode* head) {
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
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        h1 = reverse(h1);
        h2 = reverse(h2);
        int sum = 0;
        int length1 = 0;
        int length2 = 0;
        ListNode* tmp1 = h1;
        ListNode* tmp2 = h2;
        while (tmp1) {
            tmp1 = tmp1->next;
            length1++;
        }
        while (tmp2) {
            tmp2 = tmp2->next;
            length2++;
        }
        ListNode* p;
        if (length2 > length1) {
            p = h1;
            h1 = h2;
            h2 = p;
        }
        sum = 0;
        p = h1;
        while (h1) {
            if (h2) {
                sum += h2->val;
                h2 = h2->next;
            }
            sum += h1->val;
            h1->val = sum % 10;
            sum /= 10;
            if (!h1->next && sum > 0) {
                h1->next = new ListNode(sum);
                sum = 0;
            }
            h1 = h1->next;
        }
        p = reverse(p);
        return p;
    }
};
