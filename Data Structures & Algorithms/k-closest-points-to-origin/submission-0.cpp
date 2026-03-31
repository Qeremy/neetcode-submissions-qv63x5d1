class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, int>> maxHp;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int distance = x*x + y*y;
            maxHp.push({distance, i});
            if(maxHp.size() > k){
                maxHp.pop(); // remove farthest
            }
        }
        vector<vector<int>> rst;

        while(!maxHp.empty()){
            rst.push_back(points[maxHp.top().second]);
            maxHp.pop();
        }
        return rst; 
    }
};
