class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> v(s.size(), vector<int> (s.size(), 0)); 
        for(int i = s.size()-1; i >= 0; i--){
            v[i][i] = 1; 
            for(int j = i+1; j < s.size(); j++){
                v[i][j] = s[i]==s[j] ? v[i+1][j-1] + 2 : std::max(v[i+1][j], v[i][j-1]); 
            }
        }
        return v[0][s.size()-1]; 
    }
};