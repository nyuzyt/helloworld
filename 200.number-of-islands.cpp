class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m)
            return 0;
        int n = grid[0].size();
        if (!n)
            return 0;
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0' || grid[x][y] == '2')
            return;
        grid[x][y] = '2';
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }
};
