class Solution {
public:
    string minWindow(string s, string t) {
        // sliding window
        // freq table (issue is can be any letter) in this case use a hash table might be better
        int l = 0, r = 0;

        unordered_map<char, int> need;
        for(char c : t){
            need[c]++;
        }

        int require = need.size();
        int formed = 0;
        unordered_map<char, int> have;

        int min_s = MAX_INPUT;
        int min_l, min_r;
        bool has = false;
        
        while(r < s.size()){
            // need require formed
            // expand r first to include all t char
            do{
                have[s[r]]++;
                if(have[s[r]] == need[s[r]]){
                    formed++;
                }
                r++;
            } while(formed != require && r < s.size());

            if(formed == require){
                has = true;
            }
            else{
                break;
            }

            // shrink
            while(!(need.count(s[l]) && have[s[l]] == need[s[l]])){
                have[s[l]]--;
                l++;
            }

            if(r-l < min_s){
                min_s = r-l;
                min_r = r;
                min_l = l;
            }

            have[s[l]]--;
            l++;
            formed--;
            
        } // while

        if(!has){
            return "";
        }

        return s.substr(min_l, min_r);
    }
};
