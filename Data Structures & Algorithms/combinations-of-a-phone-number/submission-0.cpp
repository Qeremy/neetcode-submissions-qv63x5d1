class Solution {
public:
    vector<string> res;
    string path;
    string two = "abc", three = "def", four = "ghi", five = "jkl", six = "mno",
    seven = "pqrs", eight = "tuv", nine = "wxyz";


    void dfs(string digits, int index){
        if(index == digits.length()){
            res.push_back(path);
            return;
        }

        if(digits[index] == '2'){
            for(char c : two){
                path += c;
                dfs(digits, index+1);
                path.pop_back();
            }
        }
        else if(digits[index] == '3'){
            for(char c : three){
                path += c;
                dfs(digits, index+1);
                path.pop_back();
            }
        }
        else if(digits[index] == '4'){
            for(char c : four){
                path += c;
                dfs(digits, index+1);
                path.pop_back();
            }
        }
        else if(digits[index] == '5'){
            for(char c : five){
                path += c;
                dfs(digits, index+1);
                path.pop_back();
            }
        }
        else if(digits[index] == '6'){
            for(char c : six){
                path += c;
                dfs(digits, index+1);
                path.pop_back();
            }
        }
        else if(digits[index] == '7'){
            for(char c : seven){
                path += c;
                dfs(digits, index+1);
                path.pop_back();
            }
        }
        else if(digits[index] == '8'){
            for(char c : eight){
                path += c;
                dfs(digits, index+1);
                path.pop_back();
            }
        }
        else{
            for(char c : nine){
                path += c;
                dfs(digits, index+1);
                path.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        dfs(digits, 0);
        return res;
    }
};
