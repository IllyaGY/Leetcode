class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<long long> v(256, 0);
        v['X'] = 1; 
        v['Y'] = 1000000; 
        vector<vector<long long>> grid1 (grid.size(), vector<long long>(grid[0].size(), 0)); 
        for(int i = 0; i < grid[0].size();i++){
            for(int j = 0; j < grid.size(); j++){
                grid1[j][i] += v[grid[j][i]];
                if(j) grid1[j][i] += grid1[j-1][i];
            }
        }
         for(int i = 0; i < grid.size();i++){
            for(int j = 1; j < grid[0].size(); j++){
                grid1[i][j] += grid1[i][j-1];
            }
        }

        int c = 0; 
        for(auto &i : grid1){
            for(auto &j : i) 
                if(j && ((j % 1000000) == (j/1000000))) c++;
        }
        return c; 
    }
};
