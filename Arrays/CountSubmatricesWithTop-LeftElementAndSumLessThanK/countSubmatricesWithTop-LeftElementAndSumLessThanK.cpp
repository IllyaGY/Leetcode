class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                grid[i][j] += grid[i][j-1]; 
            }
        }
        for(int i = 0; i < grid[0].size(); i++){
            for(int j = 1; j < grid.size(); j++){
                grid[j][i] += grid[j-1][i]; 
            }
        }
        int c = 0; 
        for(auto &i : grid){
            for(auto &j : i) if(j <= k) c++;
        }
        return c; 
    }
};
