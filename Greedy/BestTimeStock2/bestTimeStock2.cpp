class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0; 
        int curr_sum = 0; 
        int min_buy = INT_MAX; 
        int bought = 0; 
        for(int i = 0; i < prices.size(); i++){
            int diff_local = prices[i] - prices[bought];
            if(diff_local <= 0){
                bought = i; 
            }
            else{
                curr_sum += diff_local; 
                bought = i;
            }
            min_buy = min(min_buy, prices[i]); 
            mx = max(max(curr_sum,prices[i] - min_buy), mx);
        }
        return mx; 
    }
};
