class Solution
{
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int length = 0;
        int y = x;
        while (y > 0) {
            length++;
            y /= 10;
        }
        // printf("%d\n",length);
        int min = 1;
        int max;
        for (int i = 1; i < (length + 1) / 2; i++)
            min *= 10;
        if (length % 2 == 0) {
            max = min * 10;
            min = max / 4;
        } else
            max = min * 4;
        if (min * min == x)
            return min;
        int tmp;
        while (max - min > 1) {
            tmp = (min + max) / 2;
            if (tmp * tmp == x)
                return tmp;
            else if (tmp > x / tmp)
                max = tmp;
            else
                min = tmp;
        }
        return min;
    }
};
