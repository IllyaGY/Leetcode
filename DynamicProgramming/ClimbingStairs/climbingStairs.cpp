class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> v(n+1,0);
        v[0] = 1;
        for(int i = 1; i <= n; i++)
            v[i] = v[i-1] + (i-2>=0 ? v[i-2] : 0);
        return v[n];
    }
};
