class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    unordered_set<int> dict;

    void dfs(vector<int>& nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!dict.count(nums[i])){
                path.push_back(nums[i]);
                dict.insert(nums[i]);

                dfs(nums);

                path.pop_back();
                dict.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }
};
