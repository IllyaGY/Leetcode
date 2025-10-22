class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<uint32_t> v (cost.size() + 2, 0);
        for(int i = 1; i <= cost.size(); i++){
            v[i] = std::min(v[i-1] + cost[i-1], (i - 2 >= 0) ? v[i-2] + cost[i-2]: 0); 
            
        }
        return v[cost.size()];
    }
};
