class TimeMap {
private:
    unordered_map<int, pair<string, string>> map;
    vector<int> time;

public:
    TimeMap() {
        // set vector<int> of timestamp
        // hash table for O(1) lookup
        
    }
    
    void set(string key, string value, int timestamp) {
        // store values in vector and hash table with corresponding values
        time.push_back(timestamp);
        map[timestamp] = {key, value};
    }
    
    string get(string key, int timestamp) {
        // binary search on timestamp and retrieve value basedn on key and timestamp
        int l = 0, r = time.size() - 1;

        int mid;

        while(l <= r){
            mid = l + (r-l)/2;
            if(time[mid] == timestamp){
                return map[time[mid]].second;
            }
            if(time[mid] > timestamp){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return map[time[mid]].second; 
    }
};
