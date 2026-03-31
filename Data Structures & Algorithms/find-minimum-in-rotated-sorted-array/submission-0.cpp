class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int minN = MAX_INPUT;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] < minN){
                minN = nums[mid];
            }
            if(nums[mid] > nums[r]){
                // mid is with l
                l = mid + 1;
            }
            else{
                // mid is with r
                r = mid - 1;
            }
        }
        return minN;
    }
};
