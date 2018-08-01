class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int tmp;
        while (end >= start) {
            tmp = (start + end) / 2;
            if (nums[tmp] == target)
                return tmp;
            else if (nums[tmp] > target)
                end = tmp - 1;
            else
                start = tmp + 1;
        }
        return -1;
    }
};
