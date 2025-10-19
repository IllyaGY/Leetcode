class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> v(triangle.size() + 2, vector<int> (triangle[triangle.size()-1].size() + 2 , INT_MAX));
        for(int i = 0; i < v.size(); i++) v[i][0] = 0; 
        for(int i = 0; i < v[0].size(); i++) v[v.size()-1][i] = 0; 
        int val = INT_MAX; 
        for(int i = v.size() - 2; i > 0; i--){
            int s = 1;
            for(int j = s; j <= triangle[i-1].size(); j++){
                int temp = std::min(v[i+1][j], v[i+1][j+1]); 
                v[i][j] = temp; 
                if(v[i][j] < INT_MAX){
                    v[i][j] += triangle[i-1][j-1]; 
                }
                else cout << 0 << " "; 
                if(i == 1) val = std::min(val, v[i][j]);
            }
            s++; 
            
        }
        return val;
    }
};
