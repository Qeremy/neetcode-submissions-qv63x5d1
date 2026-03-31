class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // index, temp value
        stack<pair<int,int>> s;
        vector<int> v(n);
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && temperatures[i] >= s.top().second){
                    s.pop();
            }
            if(!s.empty()){
                v[i] = s.top().first - i;
            }
            else{
                v[i] = 0;
            }
            s.push({i, temperatures[i]}); 
        }
        return v;
    }
};
