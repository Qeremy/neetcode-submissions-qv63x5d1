class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> in;
        unordered_map<int,int> visited;

        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            auto it = visited.find(comp);
            if(it != visited.end()){
                int j = it->second;
                return {min(i,j), max(i,j)};
            }
            visited[nums[i]] = i;
        }
        return {};
    }
};
