class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> v (101, 0);
        for(auto &i : bulbs) v[i]^=1; 
        vector<int> res; 
        for(int i = 1; i < 101; i++) if(v[i]) res.push_back(i); 
        return res; 
    }
};
