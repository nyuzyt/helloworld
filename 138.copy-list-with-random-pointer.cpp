/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return head;
        RandomListNode* tmp = head;
        while (tmp) {
            RandomListNode* newNode = new RandomListNode(tmp->label);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = newNode->next;
        }
        tmp = head;
        while (tmp) {
            if (tmp->random)
                tmp->next->random = tmp->random->next;
            tmp = tmp->next->next;
        }
        tmp = head;
        RandomListNode* newHead = head->next;
        while (tmp) {
            if (tmp->next->next) {
                RandomListNode* q = tmp->next;
                tmp->next = tmp->next->next;
                q->next = tmp->next->next;
                tmp = tmp->next;
            } else {
                tmp->next = NULL;
                tmp = tmp->next;
            }
        }
        return newHead;
    }
};
