class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = prices.size() - 1;


        int min = MAX_INPUT;
        int min_in = 0;
        int maxx = 0;
        int maxx_in = prices.size()-1;
        
        while(left < maxx_in || right > min_in){
            if(left < maxx_in){
                if(prices[left] < min){
                    min = prices[left];
                    min_in = left;
                }
                left++;
            }
            if(right > min_in){
                if(prices[right] > maxx){
                    maxx = prices[right];
                    maxx_in = right;
                }
                right--;
            }
        }

        return max(0, maxx-min);
    }
};
