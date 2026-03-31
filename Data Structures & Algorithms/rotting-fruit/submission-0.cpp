class Solution {
public:
    int minMin = INT_MIN;
    void dfs(vector<vector<int>>& grid, int row, int col, int distance){
        if(grid[row][col] == 0|| grid[row][col] == -1) return;
        if (distance >= grid[row][col]) return;
        grid[row][col] = distance;

        minMin = max(minMin, distance);
        


        if(row > 0){dfs(grid, row - 1, col, distance + 1);}
        if(row < grid.size() - 1){dfs(grid, row + 1, col, distance + 1);}
        if(col > 0){dfs(grid, row, col - 1, distance + 1);}
        if(col < grid[0].size() - 1){dfs(grid, row, col + 1, distance + 1);}

    }
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) grid[i][j] = INT_MAX; // fresh fruit
                if(grid[i][j] == 0) grid[i][j] = -1; // empty cell
                if(grid[i][j] == 2) grid[i][j] = 0; // rotten fruit
            }
        }

        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(grid[row][col] == 0){
                    if(row > 0 && grid[row - 1][col] > 0){dfs(grid, row - 1, col, 1);}
                    if(row < grid.size() - 1 && grid[row + 1][col] > 0){dfs(grid, row + 1, col, 1);}
                    if(col > 0 && grid[row][col - 1] > 0){dfs(grid, row, col - 1, 1);}
                    if(col < grid[0].size() - 1 && grid[row][col + 1] > 0){dfs(grid, row, col + 1, 1);}
                }
            }
        }
        return (minMin == INT_MIN) ? -1 : minMin;
    }
};
