class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        int low = 0;
        int high = length - 1;
        int min = nums[0];
        for (int i = 1; i < length; i++)
            if (nums[i] < min) {
                min = nums[i];
                break;
            }
        return min;
    }
};
