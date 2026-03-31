class Solution {
public:
    int trap(vector<int>& height) {
        int t_vol = 0;
        int n = height.size();
        // prefix suffix

        vector<int> ltor(n);
        vector<int> rtol(n);
        
        int left = height[0];
        for(int i = 1; i < n; i++){
            if(left > height[i]){
                ltor[i] += left - height[i];
            }
            else{
                left = height[i];
            }
        }

        int right = height[n-1];
        for(int i = n-2; i >= 0; i--){
            if(right > height[i]){
                rtol[i] += right - height[i];
            }
            else{
                right = height[i];
            }
        }

        // merge prefix and suffix and choose min
        for(int i = 0; i < n; i++){
            t_vol += min(rtol[i], ltor[i]);
        }
        return t_vol;
    }
};
