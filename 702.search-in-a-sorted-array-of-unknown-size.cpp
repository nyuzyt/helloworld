// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if (reader.get(0) == target)
            return 0;
        int tmp = 1;
        while (reader.get(tmp) < target)
            tmp *= 2;
        int low = tmp / 2;
        int high = tmp;
        int tmpValue = 0;
        while (low < high) {
            tmp = (low + high) / 2;
            tmpValue = reader.get(tmp);
            if (tmpValue == target)
                return tmp;
            else if (tmpValue > target)
                high = tmp;
            else
                low = tmp + 1;
        }
        if (reader.get(low) == target)
            return low;
        else
            return -1;
    }
};
