class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> q;
    stack<int> min_q;

    MinStack() {
    }
    
    void push(int x) {
        q.push(x);
        if (min_q.empty() || x <= getMin())
            min_q.push(x);
    }
    
    void pop() {
        if (q.top() == getMin())
            min_q.pop();
        q.pop();
    }
    
    int top() {
        return q.top();
    }
    
    int getMin() {
        return min_q.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
