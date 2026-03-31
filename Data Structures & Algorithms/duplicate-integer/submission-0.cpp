class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            if(map[nums[i]] > 1){
                return true;
            }
        }

        return false;
    }
};