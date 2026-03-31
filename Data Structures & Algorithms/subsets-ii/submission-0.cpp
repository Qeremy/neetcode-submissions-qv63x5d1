class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& nums, int start){
        res.push_back(path);

        for(int i = start; i < nums.size(); i++){

            path.push_back(nums[i]);
            if(!(i > start && nums[i] == nums[i-1])){
                dfs(nums, i + 1);
            }
            path.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};
