class KthLargest {
public:
    KthLargest(int k, vector<int> nums) : k(k) {
        for (int num : nums)
            add(num);
    }
    
    int add(int val) {
        s.insert(val);
        if (s.size() > k)
            s.erase(s.begin());
        return *s.begin();
    }

    const int k;
    multiset<int> s;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
