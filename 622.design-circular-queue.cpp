class MyCircularQueue {
public:
    vector<int> myQueue;
    int size;
    int head;
    int tail;
    int count;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : size(k), head(0), tail(0), count(0) {
        myQueue = vector<int>(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (!isFull()) {
            myQueue[head] = value;
            head = (head + 1) % size;
            count++;
            return true;
        } else
            return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!isEmpty()) {
            tail = (tail + 1) % size;
            count--;
            return true;
        } else
            return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;
        return myQueue[tail];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        return myQueue[(head + size - 1) % size];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (count == 0)
            return true;
        else
            return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (count == size)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
