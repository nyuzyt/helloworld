class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        if (total % 2 == 1)
            return findKth(nums1.begin(), nums2.begin(), m, n, total / 2 + 1);
        else
            return (findKth(nums1.begin(), nums2.begin(), m, n, total / 2) +
                    findKth(nums1.begin(), nums2.begin(), m, n, total / 2 + 1)) /
                   2.0;
    }
    int findKth(vector<int>::iterator nums1, vector<int>::iterator nums2, int m, int n, int k) {
        if (m > n)
            return findKth(nums2, nums1, n, m, k);
        if (m == 0)
            return nums2[k - 1];
        if (k == 1)
            return min(nums1[0], nums2[0]);
        int tmpa = min(k / 2, m), tmpb = k - tmpa;
        if (nums1[tmpa - 1] < nums2[tmpb - 1])
            return findKth(nums1 + tmpa, nums2, m - tmpa, n, k - tmpa);
        else if (nums1[tmpa - 1] > nums2[tmpb - 1])
            return findKth(nums1, nums2 + tmpb, m, n - tmpb, k - tmpb);
        else return nums1[tmpa - 1];
    }
};
