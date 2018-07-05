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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length = 0;
        int lengthA = 0;
        int lengthB = 0;
        if (!headA || !headB)
            return NULL;
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        while (tmpA) {
            lengthA++;
            tmpA = tmpA->next;
        }
        while (tmpB) {
            lengthB++;
            tmpB = tmpB->next;
        }
        length = abs(lengthA - lengthB);
        if (lengthB > lengthA) {
            tmpA = headA;
            headA = headB;
            headB = tmpA;
        }
        tmpA = headA;
        tmpB = headB;
        while (length > 0) {
            tmpA = tmpA->next;
            length--;
        }
        while (tmpA && tmpB) {
            if (tmpA == tmpB)
                return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return NULL;
    }
};
