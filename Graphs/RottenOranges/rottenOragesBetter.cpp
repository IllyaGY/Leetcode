class Solution {
public:

    int mn(vector<vector<int>>& grid, queue<vector<int>>&q){  
        int ctr = 0; 
        int size = q.size(); 
        while(!q.empty()){
            if(!size) {ctr++; size = q.size(); }  
            int i = q.front()[0]; int j = q.front()[1]; 
            q.pop();
            if(i >= 1 && grid[i-1][j] == 1) {q.push({i-1, j}); grid[i-1][j] = 2;}
            if(i+1 < grid.size() && grid[i+1][j] == 1) {q.push({i+1, j}); grid[i+1][j] = 2; }
            if(j >= 1 && grid[i][j-1] == 1){ q.push({i, j-1}); grid[i][j-1] = 2; }
            if(j+1 < grid[0].size() && grid[i][j+1] == 1){q.push({i, j+1}); grid[i][j+1] = 2; } 
            size--; 

            
        }
        return ctr; 
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q; 
        int m = -1; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2)  q.push({i, j});
            }
        }
        m = mn(grid, q);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return m; 
    }
};
