class MinStack {
private: 
    stack<pair<int,int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val, val});
        }
        else{
            int min_val = min(val, s.top().second);
            s.push({val, min_val});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
