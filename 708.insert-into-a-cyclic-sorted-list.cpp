/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* next = NULL;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if (!head) {
            newNode->next = newNode;
            return newNode;
        }
        Node* tmp = head->next;
        int max, min;
        max = min = head->val;
        while (tmp != head) {
            if (tmp->val > max)
                max = tmp->val;
            if (tmp->val < min)
                min = tmp->val;
            tmp = tmp->next;
        }
        if (min == max) {
            newNode->next = head->next;
            head->next = newNode;
            return head;
        }
        if (insertVal <= min || insertVal >= max) {
            tmp = head;
            while (tmp->val <= tmp->next->val)
                tmp = tmp->next;
            newNode->next = tmp->next;
            tmp->next = newNode;
            return head;
        } else {
            tmp = head;
            while (tmp) {
                if (tmp->val <= insertVal && insertVal <= tmp->next->val)
                    break;
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
            return head;
        }
    }
};
