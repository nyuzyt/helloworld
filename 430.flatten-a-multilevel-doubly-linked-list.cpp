/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flat(Node* head) {
        Node* p = head;
        while (p) {
            if (p->child) {
                Node* q = flat(p->child);
                p->child = NULL;
                if (p->next) {
                    p->next->prev = q->prev;
                    q->prev->next = p->next;
                    p->next = q;
                    q->prev = p;
                } else {
                    p->next = q;
                    q->prev = p;
                }
            }
            if (!p->next)
                head->prev = p;
            p = p->next;
        }
        return head;
    }
    Node* flatten(Node* head) {
        head = flat(head);
        if (head && head->prev)
            head->prev = NULL;
        return head;
    }
};
