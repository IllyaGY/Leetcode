class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m ;
        pair<int, int> p = {-1, -1};
        for(auto & i : nums) {
            m[i]++;
            if(p.second < m[i]) p = {i, m[i]}; 
        }
        return p.first; 
    }
};