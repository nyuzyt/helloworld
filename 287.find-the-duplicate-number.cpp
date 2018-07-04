class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int n = nums.size() - 1;
        int low = 1;
        int high = n;
        int s = 0;
        int temp = 0;
        while (low < high) {
            temp = (high - low) / 2 + low;
            s = 0;
            for (i = 0; i < n + 1; i++)
                if (nums[i] < (temp + 1) && nums[i] >= low)
                    s++;
            if (s > (temp - low + 1))
                high = temp;
            else
                low = temp + 1;
        }
        return low;
    }
};
