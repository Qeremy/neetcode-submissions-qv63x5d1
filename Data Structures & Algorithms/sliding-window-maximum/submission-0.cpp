class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        priority_queue<pair<int,int>> win;
        vector<int> result;


        for(int i = 0; i < nums.size(); i++){
            while(i < k){
                win.push({nums[i], i});
                i++;
            }
            
            result.push_back(win.top().first);
            while(win.top().second <= i - k){
                win.pop();
            }
            win.push({nums[i], i});
        }
        result.push_back(win.top().first);

        return result;

    }
};
