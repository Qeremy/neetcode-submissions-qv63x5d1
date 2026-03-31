class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')' || s[0] == '}' || s[0] == ']'){
            return false;
        }
        
        stack<char> para;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                para.push(c);
            }
            else if(!para.empty()){
                if(c == ')'){
                    if(para.top() == '('){
                        para.pop();
                    }
                    else{return false;}
                }
                else if(c == '}'){
                    if(para.top() == '{'){
                        para.pop();
                    }
                    else{return false;}
                }
                else{
                    if(para.top() == '['){
                        para.pop();
                    }
                    else{return false;}
                }
            }
            else{return false;}
        }

        if(!para.empty()){
            return false;
        }


        return true;
    }
};
