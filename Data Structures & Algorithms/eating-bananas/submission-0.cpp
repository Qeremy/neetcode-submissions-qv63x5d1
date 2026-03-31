class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k){
        // ceiling of p/k is (p+k-1) / k
        int time = 0;
        for(int pile : piles){
            time += (pile + k - 1) / k;
        }
        return (time <= h);
    }



    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int maxp = piles[piles.size()-1];
        // find min and try min 
        int l = 1, r = maxp, mink = maxp;
        
        
        // way to test if a value is valid ceil[x/t] = k
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canEat(piles, h, mid)){
                mink = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return mink;
    }
};
