class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        int num = 0;
        while (!q.empty()) {
            num++;
            int sz = q.size();
            while (sz--) {
                int tmp = q.front();
                q.pop();
                for (int i = 1; i <= n; i++) {
                    if (i * i > tmp)
                        break;
                    if (i * i == tmp)
                        return num;
                    q.push(tmp - i * i);
                }
            }
        }
    }
};
