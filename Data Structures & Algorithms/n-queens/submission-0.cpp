class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    unordered_set<int> col;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    void dfs(int row){
        // 2 diagonal: row - col & row + col
        if(row == path.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < path.size(); i++){
            if(!col.count(i)){ // check column safe
                col.insert(i);
                if(!diag1.count(row - i) && !diag2.count(row + i)){ // check diagonal safe
                    diag1.insert(row - i);
                    diag2.insert(row + i);
                    path[row][i] = 'Q';
                    dfs(row + 1);
                    path[row][i] = '.';
                    diag1.erase(row - i);
                    diag2.erase(row + i);
                }
                col.erase(i);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        path = vector<string>(n, string(n, '.'));
        dfs(0);
        return res;
    }
};
