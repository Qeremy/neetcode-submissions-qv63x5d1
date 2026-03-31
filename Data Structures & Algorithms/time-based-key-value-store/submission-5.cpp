class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> timemap;
public:
    TimeMap() {
        // set vector<int> of timestamp
        // hash table for O(1) lookup
        
    }
    
    void set(string key, string value, int timestamp) {
        // store values in vector and hash table with corresponding values
        timemap[key].push_back({value,timestamp});
        
    }
    
    string get(string key, int timestamp) {
        // binary search on timestamp and retrieve value basedn on key and timestamp
        if (!timemap.count(key)) return "";

        int l = 0, r = timemap[key].size() - 1;
        int ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(timemap[key][mid].second <= timestamp){
                ans = mid;
                l = mid+1;
            }
                
            else{
                r = mid-1;
            }
        }
        return (ans == -1) ? "" : timemap[key][ans].first;
    }
};
