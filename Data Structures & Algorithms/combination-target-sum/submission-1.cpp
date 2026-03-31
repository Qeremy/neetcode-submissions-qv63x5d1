class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& nums, int target, int start){
        if(target == 0){
            res.push_back(path);
            return;
        }
        if(target < 0) return;
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(nums, target - nums[i], i);
            path.pop_back();
        }
    }



    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, target, 0);
        return res;
    }
};
