class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix suffix
        int pre = 1;
        vector<int> res(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            res[i] *= pre;
            pre *= nums[i];
        }

        int suf = 1;
        for(int j = nums.size() - 1; j >= 0; j--){
            res[j] *= suf;
            suf *= nums[j];
        }
        return res;
    }
};
