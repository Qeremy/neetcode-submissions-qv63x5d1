class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int distance) {
        if (grid[row][col] == 0 || grid[row][col] == -1) return;
        if (distance >= grid[row][col]) return;

        grid[row][col] = distance;

        if (row > 0) dfs(grid, row - 1, col, distance + 1);
        if (row < grid.size() - 1) dfs(grid, row + 1, col, distance + 1);
        if (col > 0) dfs(grid, row, col - 1, distance + 1);
        if (col < grid[0].size() - 1) dfs(grid, row, col + 1, distance + 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) grid[i][j] = INT_MAX;
                else if (grid[i][j] == 0) grid[i][j] = -1;
                else if (grid[i][j] == 2) grid[i][j] = 0;
            }
        }

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    if (row > 0 && grid[row - 1][col] > 0) dfs(grid, row - 1, col, 1);
                    if (row < m - 1 && grid[row + 1][col] > 0) dfs(grid, row + 1, col, 1);
                    if (col > 0 && grid[row][col - 1] > 0) dfs(grid, row, col - 1, 1);
                    if (col < n - 1 && grid[row][col + 1] > 0) dfs(grid, row, col + 1, 1);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == INT_MAX) return -1;
                if (grid[i][j] > 0) ans = max(ans, grid[i][j]);
            }
        }

        return ans;
    }
};