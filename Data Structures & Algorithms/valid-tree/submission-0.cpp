class Solution {
public:
    unordered_set<int> visited;
    bool dfs(vector<vector<int>>& edges, int parent, int curr){
        if(visited.count(curr)) return false;
        visited.insert(curr);
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] == curr && edges[i][1] != parent){
                if(!dfs(edges, edges[i][0], edges[i][1])) return false;
            }
            else if(edges[i][1] == curr && edges[i][0] != parent){
                if(!dfs(edges, edges[i][1], edges[i][0])) return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // check if there's an cycle 
        if(!dfs(edges, -1, 0)) return false;
        if(visited.size() != n) return false;
        return true;
    }
};
