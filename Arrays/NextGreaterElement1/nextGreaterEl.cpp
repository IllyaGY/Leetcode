class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res; 
        for(auto i : nums1){
            mp[i] = -1; 
        }
        for (int i = 0; i < nums2.size(); i++)
            if(mp.find(nums2[i]) != mp.end()) mp[nums2[i]] = i;

        for(int i = 0; i < nums1.size(); i++){
            int &k = nums1[i]; 
            int v = mp[k]; 
            while(v < nums2.size()) {
                if(nums2[v] > k) {
                    k = nums2[v];  
                    break; 
                }
                v++; 

            }
            if(v==nums2.size()) k = -1 ; 

        }
        return nums1; 
    }
};
