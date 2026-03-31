class Solution {
public:
    string path;
    vector<string> res;



    void dfs(int n, int left, int right){
        if(right == left && right == n){
            res.push_back(path);
            return;
        }
        if(left < n){
            path += '(';
            dfs(n, left + 1, right);
            path.pop_back();
        }
        if(right < n && right < left){
            path += ')';
            dfs(n, left, right + 1);
            path.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        int left = 0, right = 0;
        dfs(n, left, right);
        return res;
    }
};
