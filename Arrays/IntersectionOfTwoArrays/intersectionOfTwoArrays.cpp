class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> seen(1001, 0);
        vector<int> r; 
        for(auto &i : nums1) if(!seen[i])seen[i]++;
        for(auto &i: nums2){
            if(seen[i]) {
                r.push_back(i);
                seen[i]--; 
            }
        }
        return r; 
    }
};
