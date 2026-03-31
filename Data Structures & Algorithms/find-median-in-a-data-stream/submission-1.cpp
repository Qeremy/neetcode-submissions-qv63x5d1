class MedianFinder {
public:
    
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;


    MedianFinder() {}
    
    void addNum(int num) {
        if(right.size() == 0) right.push(num);
        else if(left.size() == right.size()){
            if(num > right.top()){
                right.push(num);
            }
            else{
                left.push(num);
                right.push(left.top());
                left.pop();
            }
        }
        else{ // left.size() < right.size();
            if(num > right.top()){
                right.push(num);
                left.push(right.top());
                right.pop();
            }
            else{
                left.push(num);
            }
        }

    }
    
    double findMedian() {
        if(left.size() < right.size()){
            return right.top();
        }
        else{
            return (left.top() + right.top()) / 2.0;
        }
    }
};
