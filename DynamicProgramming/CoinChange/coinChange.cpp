class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> v(coins.size() + 1, vector<int> (amount + 1, 0)); 
        for(int i = 1; i < v[0].size();i++) v[0][i] = INT_MAX; 
        int min = -1;
        for(int i = 1; i < v.size(); i++){
            for(int j = 1; j < v[0].size(); j++){
                v[i][j]=v[i-1][j]; 
                if(j >= coins[i-1]) {
                    if(v[i][j-coins[i-1]] < INT_MAX) v[i][j] = std::min(v[i][j-coins[i-1]]+1, v[i][j]); // The values in the current row, will either be the same or better, so no need to do std::min with the previous row.
                }
                
            }
            if(min == -1 || v[i][amount] < min) min = v[i][amount];  
        }
        return (min != INT_MAX) ? min : -1;
    }
};
