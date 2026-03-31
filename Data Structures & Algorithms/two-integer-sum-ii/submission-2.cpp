class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        int sum = numbers[left] + numbers[right];
        while(sum != target && left < right){
            
            if(sum < target){
                left++;
            }
            else if(sum > target){
                right--;
            }
            else{
                break;
            }
            sum = numbers[left] + numbers[right];
        }
        return {left++, right++};
        
    }
};
