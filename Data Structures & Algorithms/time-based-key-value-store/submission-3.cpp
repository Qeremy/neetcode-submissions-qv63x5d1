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
        map[key].push_back({value,timestamp});
        
    }
    
    string get(string key, int timestamp) {
        // binary search on timestamp and retrieve value basedn on key and timestamp
        int l = 0, r = timemap[key].size() - 1;
        int mid;

        while(l <= r){
            mid = l + (r-l)/2;
            if(timemap[key][mid].second == timestamp){
                return timemap[key][mid].first;
            }
            if(timemap[key][mid].second > timestamp){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return timemap[key][mid].first;
    }
};
