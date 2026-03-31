class Solution {
public:
    unordered_set<int> pacific;
    unordered_set<int> atlantic;

    void pacific_dfs(vector<vector<int>>& heights, int r, int c){
        int index = r * heights[0].size() + c;
        pacific.insert(index);
        if(r > 0 && !pacific.count((r - 1) * heights[0].size() + c)){
            if(heights[r][c] <= heights[r - 1][c]) pacific_dfs(heights, r - 1, c);
        }
        if(r < heights.size() - 1 && !pacific.count((r + 1) * heights[0].size() + c)){
            if(heights[r][c] <= heights[r + 1][c]) pacific_dfs(heights, r + 1, c);
        }
        if(c > 0 && !pacific.count(r * heights[0].size() + c - 1)){
            if(heights[r][c] <= heights[r][c - 1]) pacific_dfs(heights, r, c - 1);
        }
        if(c < heights[0].size() - 1 && !pacific.count(r * heights[0].size() + c + 1)){
            if(heights[r][c] <= heights[r][c + 1]) pacific_dfs(heights, r, c + 1);
        }
    }

    void atlantic_dfs(vector<vector<int>>& heights, int r, int c){
        int index = r * heights[0].size() + c;
        atlantic.insert(index);

        if(r > 0 && !atlantic.count((r - 1) * heights[0].size() + c)){
            if(heights[r][c] <= heights[r - 1][c]) atlantic_dfs(heights, r - 1, c);
        }
        if(r < heights.size() - 1 && !atlantic.count((r + 1) * heights[0].size() + c)){
            if(heights[r][c] <= heights[r + 1][c]) atlantic_dfs(heights, r + 1, c);
        }
        if(c > 0 && !atlantic.count(r * heights[0].size() + c - 1)){
            if(heights[r][c] <= heights[r][c - 1]) atlantic_dfs(heights, r, c - 1);
        }
        if(c < heights[0].size() - 1 && !atlantic.count(r * heights[0].size() + c + 1)){
            if(heights[r][c] <= heights[r][c + 1]) atlantic_dfs(heights, r, c + 1);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        for(int i = 0; i < m; i++){
            pacific_dfs(heights, i, 0);
            atlantic_dfs(heights, i, n - 1);
        }
        for(int j = 0; j < n; j++){
            pacific_dfs(heights, 0, j);
            atlantic_dfs(heights, m - 1, j);
        }

        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int height = i * n + j;
                if(pacific.count(height) && atlantic.count(height)){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
