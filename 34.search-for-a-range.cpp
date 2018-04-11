class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> res;
        if (length == 0) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int low = 0;
        int high = length - 1;
        while (low < high) {
            int tmp = (high - low) / 2 + low;
            if (nums[tmp] == target) {
                if (tmp == 0) {
                    low = 0;
                    break;
                } else if (nums[tmp - 1] < target) {
                    low = tmp;
                    break;
                } else
                    high = tmp - 1;
            }
            if (nums[tmp] < target)
                low = tmp + 1;
            else if (nums[tmp] > target)
                high = tmp - 1;
        }
        if (nums[low] == target)
            res.push_back(low);
        else
            res.push_back(-1);
        low = 0;
        high = length - 1;
        while (low < high) {
            int tmp = (high - low) / 2 + low;
            // cout << tmp << " ";
            if (nums[tmp] == target) {
                if (tmp == length - 1) {
                    low = length - 1;
                    break;
                } else if (nums[tmp + 1] > target) {
                    low = tmp;
                    break;
                } else
                    low = tmp + 1;
            }
            if (nums[tmp] < target)
                low = tmp + 1;
            else if (nums[tmp] > target)
                high = tmp - 1;
        }
        if (nums[low] == target)
            res.push_back(low);
        else
            res.push_back(-1);

        return res;
    }
};
