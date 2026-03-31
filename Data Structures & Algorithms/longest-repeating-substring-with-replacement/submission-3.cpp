class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s == ""){
            return 0;
        }
        int max_length = 0;
        vector<int> freq(26,0);
        int max_freq = 0;
        
        //sliding window and keeping track of max freq
        int l = 0;
        int r = 0;
        int current_length = 0;
        
        // window size + 1 - max freq element <= k
        while(r < s.length()){
            // find max_freq
            freq[s[r] - 'A']++;
            max_freq = max(max_freq, freq[s[r] - 'A']);

            if(r-l + 1 - max_freq <= k){
                r++;
                current_length++;
                max_length = max(max_length, current_length);
            }
            else{
                while(r-l + 1 - max_freq > k){
                    freq[s[l] - 'A']--;
                    current_length--;
                    l++;
                }
                r++;
                current_length++;
            }
        }
        return max_length;
    }
};
