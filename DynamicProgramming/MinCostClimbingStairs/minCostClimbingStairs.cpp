class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<vector<int>> v (cost.size() + 1, vector<int> (cost.size()+2, 0));
        for(int i = 1; i < v.size(); i++){
            for(int j = 1; j < v[0].size(); j++){
                v[i][j] = std::min(v[i-1][j] + cost[i-1], (i - 2 >= 0) ? v[i-2][j] + cost[i-2]: 0); 
            }
        }
        return v[v.size()-1][v.size()];
    }
<<<<<<< HEAD
};
=======
};
>>>>>>> 8f9ca37dc7416f30c2dcc365e50af422c6e17f3e
