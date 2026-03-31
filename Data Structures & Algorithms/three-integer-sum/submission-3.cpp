class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triples;

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            vector<int> entry(3);
            entry[0] = nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){
                if(-nums[i] == nums[left] + nums[right]){
                    entry[1] = nums[left];
                    entry[2] = nums[right];
                    triples.push_back(entry);
                    left++;
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                    right--;
                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
                else if(-nums[i] > nums[left] + nums[right]){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return triples;
    }
};
