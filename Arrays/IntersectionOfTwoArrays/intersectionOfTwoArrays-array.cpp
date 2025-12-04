class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s(1001, 0);
        vector<int> res; 
        for(auto &i : nums1) if(!s[i]) s[i]++;
        for(auto &i : nums2){
            if(s[i]-- > 0)
                res.push_back(i);
        } 
        return res;
    }
};
