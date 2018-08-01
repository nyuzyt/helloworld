#include <iostream>
using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct node {
        int val;
        node *next, *prev;
        node(int x) : val(x), next(NULL), prev(NULL) {
        }
    };

    node* head;
    MyLinkedList() {
        head = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        node* tmp = head;
        int tmpIndex = 0;
        if (!tmp)
            return -1;
        else {
            while (tmp->next && tmpIndex < index) {
                tmpIndex++;
                tmp = tmp->next;
            }
            if (tmpIndex == index)
                return tmp->val;
            else
                return -1;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (!head)
            head = new node(val);
        else {
            node* tmpHead = head;
            node* tmp = new node(val);
            head = tmp;
            head->next = tmpHead;
            tmpHead->prev = head;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!head)
            head = new node(val);
        else {
            node* tmp = head;
            while (tmp->next)
                tmp = tmp->next;
            node* tmpNew = new node(val);
            tmp->next = tmpNew;
            tmpNew->prev = tmp;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        node* tmp = head;
        int tmpIndex = 0;
        if (index == 0)
            addAtHead(val);
        else {
            if (!tmp)
                return;
            while (tmp->next && tmpIndex < index - 1) {
                tmpIndex++;
                tmp = tmp->next;
            }
            if (tmpIndex == index - 1) {
                node* tmpNew = new node(val);
                tmpNew->next = tmp->next;
                tmpNew->prev = tmp;
                tmp->next = tmpNew;
                if (tmpNew->next)
                    tmpNew->next->prev = tmpNew;
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        node* tmp = head;
        int tmpIndex = 0;
        if (tmp) {
            while (tmp->next && tmpIndex < index - 1) {
                tmpIndex++;
                tmp = tmp->next;
            }
            if ((tmpIndex == index - 1) && tmp->next) {
                tmp->next = tmp->next->next;
                if (tmp->next)
                    tmp->next->prev = tmp;
            }
        }
    }
    void traverse() {
        node* tmp = head;
        while (tmp) {
            cout << tmp->val;
            tmp = tmp->next;
        }
        cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
