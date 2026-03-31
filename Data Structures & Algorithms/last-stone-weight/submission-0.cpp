class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones){
            pq.push(stone);
        }
        int heavier, heavy;
        while(pq.size() > 1){
            heavier = pq.top();
            pq.pop();
            heavy = pq.top();
            pq.pop();
            int remaining = heavier - heavy;
            if(remaining > 0) pq.push(remaining);
        }
        return pq.top();

    }
};
