class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // sliding window with O(n) time and O(1) space
        int n = s1.length();

        // freq table
        vector<int> freq(26,0);
        for(int i = 0; i < n; i++){
            freq[s1[i] - 'a']++;
        }

        // window freq table
        vector<int> win(26,0);
        for(int i = 0; i < n; i++){
            win[s2[i] - 'a']++;
        }
        
        for(int i = 0; i < s2.length() - n; i++){
            if(freq == win){
                return true;
            }
            win[s2[i] - 'a']--;
            win[s2[i+n] - 'a']++;
        }
        
        return false;
    }
};
