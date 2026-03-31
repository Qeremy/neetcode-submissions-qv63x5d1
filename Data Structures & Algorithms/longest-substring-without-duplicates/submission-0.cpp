class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0){
            return 0;
        }

        int max_length = 0;
        int current_length = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> dict;

        while(r < n - 1){
            if(dict.count(s[r]) != 0){
                // append left side until no more duplicates in the dict
                // remove all char appended from the dict
                
                while(dict.count(s[r]) != 0){
                    dict.erase(s[l]);
                    current_length--;
                    l++;
                }
                dict.insert(s[r]);
                r++;
                current_length++;
            }
            else{
                // shift right by one, push new char to dict, increase current length by 1, take max length 
                dict.insert(s[r]);
                current_length++;
                max_length = max(max_length, current_length);
                r++;
            }
        }

        return max_length;
    }
};
