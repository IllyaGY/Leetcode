#SLOW -- O(n^2 * sqrt(n)) - REDO TOMORROW ASAP 
class Solution {
public:
    int numSquares(int n) {
        vector<vector<int>> v(2, vector<int>(n+1, 0));  
        vector<int> v1(n+1, 0); 
        int ctr = 0; 
        int var = ctr*ctr; 
        while(var < v1.size()){
            v1[var] = 1; 
            ctr++; 
            var = ctr*ctr; 
        } 
        for(int i = 1; i <= n; i++){
            //v[i][0] = INT_MAX; 
            v[0][i] = INT_MAX; 
        }
        for(int i = 1; i <= n ;i++){
            int perf = int(sqrt(i)); 
            if(!v1[i]) continue; 
            else{
                for(int j = 1; j <=n; j++) {
                    int prev = j >= i ? v[1][j-i] : INT_MAX;
                    prev = (prev == INT_MAX) ? v[0][j] : std::min(prev+1, v[0][j]); 
                    v[1][j] = prev;
                }
            }
            swap(v[0], v[1]); 
        }
        return v[0][n]; 
    }
};