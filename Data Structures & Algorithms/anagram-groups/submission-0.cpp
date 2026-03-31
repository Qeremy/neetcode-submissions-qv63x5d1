class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort then unordered_map <string, vector<string>>
        unordered_map <string, vector<string>> list;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            list[sorted_s].push_back(s);

        }
        vector<vector<string>> out;
        for(auto const& it : list){
            out.push_back(it.second);
        }
        return out;
    }
};
