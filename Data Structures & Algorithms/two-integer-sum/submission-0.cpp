class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> in(2);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > target){
                continue;
            }
            int a = nums[i];
            in[0] = i;
            for(int j = i; j < nums.size(); j++){
                if(a + nums[j] == target){
                    in[1] = j;
                    return in;
                }
            }
        }
        return in;
    }
};
