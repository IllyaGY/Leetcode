class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> v (1001, {0,0});
        for(int i = 0; i < trips.size(); i++){
            v[trips[i][1]].first += trips[i][0]; 
            v[trips[i][2]].second += trips[i][0];

        }
        int temp = 0; 
        for(int i = 1; i < 1001; i++){
            v[i].second += v[i-1].second; 
            v[i].first += v[i-1].first;
        }
        for(int i = 0; i < v.size(); i++){
            if(v[i].first - v[i].second > capacity) return 0; 
        }
        return 1; 
    }
};