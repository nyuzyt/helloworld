class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> s;
        if (!nums.size())
            return false;
        for (int i = 0; i < nums.size(); i++) {
            if (s.size() > k)
                s.erase(nums[i - k - 1]);
            set<long long>::iterator lower = s.lower_bound(long(nums[i]) - t);
            if (lower != s.end() && abs(nums[i] - *lower) <= t)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};

