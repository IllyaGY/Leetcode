class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int y = obstacleGrid.size(); 
        int x = obstacleGrid[0].size(); 
        vector<vector<int>> v(y + 1, vector<int>(x+1, 0)); 
        v[1][0] = 1; 
        for(int i = 1; i <= y; i++){
            for(int j = 1; j <= x; j++){
                if(obstacleGrid[i-1][j-1]) v[i][j] = 0; 
                else v[i][j] = v[i-1][j] + v[i][j-1]; 
            }
        }
        return v[y][x]; 
    }
};
