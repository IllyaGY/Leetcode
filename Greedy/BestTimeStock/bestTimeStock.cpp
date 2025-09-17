class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0; 
        int curr = prices[0]; 
        for(int i = 0; i < prices.size(); i++){ 
            if(prices[i] - curr < 0) curr = prices[i]; 
            else mx = max(mx, prices[i] - curr); 
        }
        return mx; 
    }
};
