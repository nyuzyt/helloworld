class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int length = nums.size();
        if (length == 1)
            return 0;
        int low = 0;
        int high = length - 1;
        if (nums[low] > nums[low + 1])
            return low;
        if (nums[high] > nums[high - 1])
            return high;
        while (low < high) {
            int tmp = (high - low) / 2 + low;
            if (nums[tmp] < nums[tmp - 1])
                high = tmp - 1;
            else if (nums[tmp] < nums[tmp + 1])
                low = tmp + 1;
            else
                return tmp;
        }
        return low;
    }
};
