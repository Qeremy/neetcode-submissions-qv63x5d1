class Solution {
public:
    bool isValid(string s) {
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
        }



        return true;
    }
};
