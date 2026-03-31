class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    bool isSubPalin(string s, int l, int r){
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++; 
            r--;
        }
        return true;
    }

    void dfs(string s, int start){
        if(start == s.size()){
            res.push_back(path);
        }
        for(int i = start; i < s.size(); i++){
            path.push_back(s.substr(start, i - start + 1));
            if(isSubPalin(s, start, i)){
                dfs(s, i + 1);
            }
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
};
