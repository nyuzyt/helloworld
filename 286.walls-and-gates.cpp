class Solution {
public:
    struct point {
        int x, y;
        point(int a, int b) : x(a), y(b) {
        }
    };

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0)
            return;
        int n = rooms[0].size();
        int INF = 2147483647;
        queue<point> nodes;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0) {
                    point tmp(i, j);
                    nodes.push(tmp);
                }
        while (!nodes.empty()) {
            point tmp = nodes.front();
            nodes.pop();
            point tmp1(tmp.x - 1, tmp.y);
            point tmp2(tmp.x + 1, tmp.y);
            point tmp3(tmp.x, tmp.y - 1);
            point tmp4(tmp.x, tmp.y + 1);
            if (tmp1.x >= 0 && rooms[tmp1.x][tmp1.y] == INF) {
                rooms[tmp1.x][tmp1.y] = rooms[tmp.x][tmp.y] + 1;
                nodes.push(tmp1);
            }

            if (tmp2.x < m && rooms[tmp2.x][tmp2.y] == INF) {
                rooms[tmp2.x][tmp2.y] = rooms[tmp.x][tmp.y] + 1;
                nodes.push(tmp2);
            }

            if (tmp3.y >= 0 && rooms[tmp3.x][tmp3.y] == INF) {
                rooms[tmp3.x][tmp3.y] = rooms[tmp.x][tmp.y] + 1;
                nodes.push(tmp3);
            }

            if (tmp4.y < n && rooms[tmp4.x][tmp4.y] == INF) {
                rooms[tmp4.x][tmp4.y] = rooms[tmp.x][tmp.y] + 1;
                nodes.push(tmp4);
            }
        }
    }
};
