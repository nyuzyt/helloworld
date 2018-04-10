// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        if (isBadVersion(low))
            return low;
        while (low < high) {
            int tmp = (high - low) / 2 + low;
            if (isBadVersion(tmp) && !isBadVersion(tmp - 1))
                return tmp;
            if (isBadVersion(tmp))
                high = tmp - 1;
            else
                low = tmp + 1;
        }
        return low;
    }
};
