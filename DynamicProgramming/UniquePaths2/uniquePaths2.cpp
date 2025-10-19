class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); 
        int n = obstacleGrid[0].size(); 
        vector<vector<unsigned int>> v(m+1, vector<unsigned int>(n+1, 0)); 
        v[0][1] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(!obstacleGrid[i-1][j-1]) 
                    v[i][j] = v[i-1][j] + v[i][j-1] ; 
            }
        }
        return v[m][n]; 
    }
};

