class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        priority_queue<pair<int,int>> win;
        vector<int> result;


        for (int i = 0; i < nums.size(); i++) {
            win.push({nums[i], i});

            while (!win.empty() && win.top().second < i - k + 1) {
                win.pop();
            }

            if (i >= k - 1) {
                result.push_back(win.top().first);
            }
        }

        return result;

    }
};
