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
                int i = left.top();
                right.push(i);
                left.pop();
                left.push(num);
            }
        }
        else{ // left.size() < right.size();
            if(num > right.top()){
                int i = right.top();
                left.push(i);
                right.pop();
                right.push(num);
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
