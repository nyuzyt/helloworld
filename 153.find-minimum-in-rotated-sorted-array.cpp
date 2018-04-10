class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        int low = 0;
        int high = length - 1;
        while (low < high && nums[low] > nums[high]) {
            int tmp = (high - low) / 2 + low;
            if (nums[tmp] < nums[tmp - 1]) {
                low = tmp;
                break;
            }
            if (nums[tmp] > nums[high])
                low = tmp + 1;
            else
                high = tmp - 1;
        }
        return nums[low];
    }
};
