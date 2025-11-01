class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<vector<int>> v; 
        v.push({0,0,1}); 
        int sh = INT_MAX; 
        while(!v.empty()){
            vector<int> pt = v.front(); 
            v.pop(); 
            if(pt[0] >= grid.size() || pt[1] >= grid.size() || grid[pt[0]][pt[1]]) continue; 
            int f = pt[0]; 
            int s = pt[1];
            int p = pt[2];
            grid[f][s] = 1;
            if(pt[0] == grid.size()-1 && pt[1] == pt[0]) sh = std::min(pt[2], sh); 
            v.push({f+1, s,p+1});
            v.push({f-1, s,p+1});

            v.push({f+1, s+1,p+1});
            v.push({f-1, s+1,p+1});
            
            v.push({f+1, s-1,p+1});
            v.push({f-1, s-1,p+1});

            v.push({f, s-1,p+1});
            v.push({f, s+1,p+1});
        }
        return sh < INT_MAX ? sh : -1; 
    }
};