class Solution {
public:
    int maxArea(vector<int>& heights) {
        // sliding window
        int left = 0;
        int right  = heights.size()-1;
        int max_vol = 0;
        while(left < right){
            // volumn = min(heights[left],height[right]) * (right-left)
            int vol =  min(heights[left],heights[right]) * (right-left);
            max_vol = max(max_vol, vol);
            if(heights[left] >= heights[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return max_vol;
    }
};
