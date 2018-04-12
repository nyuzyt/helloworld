class Solution {
public:
    bool isPerfectSquare(int num) {
        int length = 0;
        int tmp = num;
        while (tmp > 0) {
            tmp /= 10;
            length++;
        }
        if (length == 0)
            return 0;
        // 1 0-3
        // 2 3-10
        // 3 10-33
        // 4 33-100
        // 5 100-333
        int max, min;
        min = length / 2;
        // 1 0
        // 2 1
        // 3 1
        int sum = 1;
        for (int i = 0; i < min; i++)
            sum *= 10;
        if (length % 2 == 1) {
            min = sum;
            max = 10 * min / 3;
        } else {
            max = sum;
            min = max / 4;
        }
        bool flag = false;
        for (int i = min; i <= max; i++)
            if (i * i == num) {
                flag = true;
                break;
            }
        return flag;
    }
};
