class Solution {
public:
    int tribonacci(int n) {
        vector<int> f(n + 1, 1);
        f[0] = 0; 
        for(int i = 3; i <= n; i++){
            f[i] = f[i-1] + f[i-2] + f[i-3];
        }
        return f[n]; 
    }
};
