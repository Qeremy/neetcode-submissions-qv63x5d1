class Solution {
public:

    string encode(vector<string>& strs) {
        string en;
        for(string str : strs){
            en += to_string(str.size()) + '#' + str;
        }
        return en;
    }

    vector<string> decode(string s) {
        vector<string> de;
        int i = 0;

        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            // 4#asdf
            int length = stoi(s.substr(i,j - i));
            de.push_back(s.substr(j+1,length));
            i = j + length + 1;
        }
        return de;
    }
};
