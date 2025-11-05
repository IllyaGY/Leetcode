class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end()); 
        vector<int> v(pairs.size(), 1); 
        for(int i = 1; i < pairs.size(); i++){
            for(int j = 0; j < i; j++){
                v[i] = std::max(v[i], v[j] + (pairs[j][1] < pairs[i][0])); 
            }   
        }
        int mx = 0;
        for(auto &i : v) mx = std::max(mx, i); 
        return mx;  
    }
};
