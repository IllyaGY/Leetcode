class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n + 2, 1);
        v[0] = 0; 
        for(int i = 2; i < n+2; i++) v[i] = v[i-2] + v[i-1];  
        return v[n+1]; 
    }
};
