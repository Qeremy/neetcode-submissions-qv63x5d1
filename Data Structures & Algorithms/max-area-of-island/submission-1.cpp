class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        int area = 1;
        if(row > 0){
            area += dfs(grid, row - 1, col);
        }
        if(row < grid.size() - 1){
            area += dfs(grid, row + 1, col);
        }
        if(col > 0){
            area += dfs(grid, row, col - 1);
        }
        if(col < grid[0].size() - 1){
            area += dfs(grid, row, col + 1);
        }
        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = INT_MIN;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
