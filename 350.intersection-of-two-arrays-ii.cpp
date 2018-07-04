class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        vector<int> result;
        if (length1 == 0 || length2 == 0)
            return result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i, j;
        i = j = 0;
        while (i < length1 && j < length2)
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        return result;
    }
};
