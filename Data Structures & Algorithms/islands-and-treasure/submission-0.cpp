class Solution {

public:
    void dfs(vector<vector<int>>& grid, int row, int col, int distance){
        if(grid[row][col] == -1 || grid[row][col] == 0) return;
        if(grid[row][col] > distance){
            grid[row][col] = distance;
            if(row > 0){
                dfs(grid, row - 1, col, distance + 1);
            }
            if(row < grid.size() - 1){
                dfs(grid, row + 1, col, distance + 1);
            }
            if(col > 0){
                dfs(grid, row, col - 1, distance + 1);
            }
            if(col < grid[0].size() - 1){
                dfs(grid, row, col + 1, distance + 1);
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // dfs when a treasure is found
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    if(i > 0) dfs(grid, i - 1, j, 1);
                    if(i < grid.size() - 1) dfs(grid, i + 1, j, 1);
                    if(j > 0) dfs(grid, i, j - 1, 1);
                    if(j < grid[0].size() - 1) dfs(grid, i, j + 1, 1);
                }
            }
        }
    }
};
