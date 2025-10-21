class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<unsigned int>> v(grid.size()+1, vector<unsigned int>(grid[0].size()+1, 0)); 
        for(int i = 0; i < v[0].size(); i++)v[0][i] = INT_MAX; 
        for(int i = 0; i < v.size(); i++)v[i][0] = INT_MAX; 
        v[1][0] = 0;
        for(int i = 1; i < v.size(); i++){
            for(int j = 1; j < v[0].size(); j++){
                v[i][j] = std::min(v[i][j-1], v[i-1][j]) + grid[i-1][j-1];
            }
        }
        return v[grid.size()][grid[0].size()]; 
    }
};
