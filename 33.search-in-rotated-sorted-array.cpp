class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int length = nums.size();
        if (length == 0)
            return -1;
        int high = length - 1;
        int tmp;
        while (low < high && nums[low] > nums[high]) {
            tmp = (low + high) / 2;
            if (nums[tmp] < nums[tmp - 1]) {
                low = tmp;
                break;
            }
            if (nums[tmp] > nums[high])
                low = tmp + 1;
            else
                high = tmp - 1;
        }
        high = low + length - 1;
        if (nums[low] > target)
            return -1;
        if (nums[low] == target)
            return low;
        if (nums[high % length] < target)
            return -1;
        if (nums[high % length] == target)
            return high % length;
        while (low < high) {
            tmp = (low + high) / 2;
            if (nums[tmp % length] == target)
                return tmp % length;
            if (nums[tmp % length] < target)
                low = (tmp + 1);
            else
                high = tmp - 1;
        }
        if (nums[low % length] != target)
            return -1;
        else
            return low % length;
    }
};
