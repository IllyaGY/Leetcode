class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> v(s.size(), vector<int> (s.size(), 0)); 
        vector<int> mx {0, 0}; 
        for(int i = s.size()-1; i >= 0; i--){
            v[i][i] = 1; 
            for(int j = i+1; j < s.size(); j++){
                if (s[i] == s[j] && (j - i < 2 || v[i+1][j-1])) {
                    v[i][j] = 1; 
                    if ((j - i + 1) > (mx[1] - mx[0] + 1)) mx = {i, j}; 
                } 
                
            }
        }
        return s.substr(mx[0],mx[1]-mx[0] + 1);
    }
};
