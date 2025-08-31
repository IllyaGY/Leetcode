class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int mins = 0; 
        queue<pair<int,int>> q; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int minCount = 0;
        int size = q.size(); 
        while(!q.empty()){
            pair<int,int> p = q.front(); 
            int i = p.first; 
            int j = p.second; 
            q.pop();
            size--; 
            grid[i][j] = ((grid[i][j] == 1 || grid[i][j] == -1) ? 2 : grid[i][j]); 
            if(i+1<grid.size() && grid[i+1][j]==1){
                grid[i+1][j] = -1;  
                q.push({i+1, j});
            }
            if(i && grid[i-1][j]==1){
                grid[i-1][j] = -1;  
                q.push({i-1, j});
            }
            if(j+1<grid[0].size() && grid[i][j+1]==1){
                grid[i][j+1] = -1;  
                q.push({i, j+1});
            }
            if(j && grid[i][j-1]==1){
                grid[i][j-1] = -1;  
                q.push({i, j-1});
            }
            if(q.empty()) break; 
            if(!size){
                minCount++; 
                size = q.size();
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1; 
                }
            }
        }
        return minCount; 
    }
};
