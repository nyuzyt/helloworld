class MovingAverage {
public:
    queue<int> q;
    int size;
    double sum;
    /** Initialize your data structure here. */
    MovingAverage(int size) : size(size), sum(0) {
    }
    
    double next(int val) {
        sum *= q.size();
        if (q.size() == size) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        sum /= q.size();
        return sum;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
