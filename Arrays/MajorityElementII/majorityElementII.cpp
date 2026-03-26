class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int d = nums.size()/3; 
        unordered_map<int, int> v; 
        vector<int> r; 
        for(auto &&i : nums) {
            v[i]++; 
        }
        for(auto &&i : v) if(i.second > d) r.emplace_back(i.first); 
        return r; 
    }
};
