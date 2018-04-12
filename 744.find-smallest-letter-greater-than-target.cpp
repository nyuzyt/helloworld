class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int length = letters.size();
        int low = 0;
        int high = length - 1;
        if (target >= letters[high])
            return letters[0];
        while (low <= high) {
            int tmp = (high - low) / 2 + low;
            if (letters[tmp] <= target)
                low = tmp + 1;
            else
                high = tmp - 1;
        }
        return letters[low];
    }
};
