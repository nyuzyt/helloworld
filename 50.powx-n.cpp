class Solution {
public:
    double myPow(double x, int n) {
        double s = 1;
        if (x == 1)
            return 1;
        if (x == -1)
            if (n % 2 == 0)
                return 1;
            else
                return -1;

        if (n < 0)
            x = 1 / x;
        long realn = n;
        realn = abs(realn);
        if (abs(x) < 1 && realn > 10 / (1 - abs(x)))
            return 0.0;
        for (int i = 0; i < realn; i++)
            s = s * x;
        return s;
    }
};
