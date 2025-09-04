class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0; 
        int buy = 0, sell = 0; 

        while(sell < prices.size()){
            int diff = prices[sell] - prices[buy]; 
            if(diff <= max){
                if(diff < 0)
                    buy = sell; 
            } 
            else {
                max = prices[sell] - prices[buy]; 
            }
            sell++;
        }
        return max; 
    }
};
