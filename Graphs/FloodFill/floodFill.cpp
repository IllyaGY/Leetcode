class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) { 
        queue<vector<int>> q; 
        if(image[sr][sc] == color) return image;
        int def = image[sr][sc]; 
        q.push({sr,sc}); 
        while(!q.empty()){
            int r = q.front()[0]; 
            int c = q.front()[1];
            q.pop();
            if(image[r][c] != def) continue; 
            if(r >= 1 && image[r-1][c] == image[r][c]) q.push({r-1, c});
            if(r+1 < image.size() && image[r+1][c] == image[r][c]) q.push({r+1, c});
            if(c >= 1 && image[r][c-1] == image[r][c]) q.push({r, c-1});
            if(c+1 < image[0].size() && image[r][c+1] == image[r][c]) q.push({r, c+1});
            image[r][c] = color; 
        }
        return image; 
    }
};
