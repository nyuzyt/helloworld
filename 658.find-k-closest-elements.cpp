class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int length = arr.size();
        int low = 0;
        int high = length - 1;
        vector<int> res;
        while (low < high) {
            int tmp = (high - low) / 2 + low;
            if (arr[tmp] == x) {
                low = tmp;
                break;
            }
            if (arr[tmp] < x)
                low = tmp + 1;
            else
                high = tmp - 1;
        }
        // cout << low << endl;
        int count = 0;
        int left = low - 1;
        int right = low;
        while (count < k) {
            if (left < 0)
                res.push_back(arr[right++]);
            else if (right >= length)
                res.push_back(arr[left--]);
            else if (abs(arr[left] - x) > abs(arr[right] - x))
                res.push_back(arr[right++]);
            else
                res.push_back(arr[left--]);
            count++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
