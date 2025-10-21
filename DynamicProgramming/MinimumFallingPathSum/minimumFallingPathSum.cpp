class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mtr = matrix.size(); 
        vector<vector<int>> v(mtr + 2, vector<int> (mtr + 2,  INT_MAX));
        for(int i = 0; i < v.size(); i++) v[0][i] = 0; 
        for(int i = 1; i <= mtr; i++){ 
            for(int j = 1; j <= mtr; j++){
                v[i][j] = std::min(v[i][j],
                    std::min(v[i-1][j],
                    std::min(v[i-1][j-1], v[i-1][j+1])) + matrix[i-1][j-1]);
            }
        }
        int mn = INT_MAX; 
        for(int i =1 ; i <= mtr; i++) mn = std::min(mn, v[mtr][i]);
        return mn;

    }
};