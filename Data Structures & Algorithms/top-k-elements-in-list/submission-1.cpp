class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        for(auto const& it : freq){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> out(k);
        for(int i = 0; i < k; i++){
            out.push_back(pq.top());
            pq.pop();
        }
        return out;
    }
};
