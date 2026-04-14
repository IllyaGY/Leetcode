class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() && !word2.size() ) return word1.size(); 
        if(word2.size() && !word1.size()) return word2.size();
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp (word1.size()+1, vector<int> (word2.size() + 1, 0));
        dp[0][0] = 0; 
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 1; i <= word1.size(); i++){
            
            for(int j = 1; j <= word2.size(); j++){
                dp[i][j] = dp[i - 1][j - 1]; 
                if(word1[i-1] != word2[j-1]) dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1])) + 1; 
            }
            
        }
        return dp[word1.size()][word2.size()] > 500 ? 0 : dp[word1.size()][word2.size()]; 
    }
};
