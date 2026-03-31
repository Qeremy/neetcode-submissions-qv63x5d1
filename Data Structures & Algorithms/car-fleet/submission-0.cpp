class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // sorting position and speed based on position
        vector<pair<int, int>> sorted(n);
        for(int i = 0; i < n; i++){
            sorted[i] = {position[i], speed[i]};
        }
        sort(sorted.begin(), sorted.end());

        // position / speed
        stack<pair<int, int>> s;
        for(int i = 0; i < n; i++){
            s.push({sorted[i].first, sorted[i].second});
        }

        int t = 0;
        int count = 0;
        while(!s.empty()){
            int time = (target - s.top().first) / s.top().second;
            s.pop();
            // if time > t then time, t = time (time slower than t)
            if(time > t){
                t = time;
                count++;
            }
        }
        return count;
    }
};
