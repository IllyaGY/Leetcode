class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<unsigned int>> v(coins.size()+1, vector<unsigned int> (amount + 1, 0));
        for(int i = 1; i < v.size(); i++){
            v[i][0] = 1; 
            for(int j = 1; j <= amount; j++){
                v[i][j] = v[i-1][j] + (j - coins[i-1] >= 0 ? v[i][j-coins[i-1]] : 0);

            }
        }
        return v[coins.size()][amount]; 
    }
};
