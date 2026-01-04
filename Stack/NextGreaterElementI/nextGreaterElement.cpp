class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> q; 
        unordered_map<int, int> v; 
        for(auto &i : nums1) v[i] = -1;  
        for(int i = 0; i < nums2.size(); i++){
            while(!q.empty() && nums2[i] > q.top()){ 
                v[q.top()] = nums2[i];
                q.pop(); 
            }
            if(v[nums2[i]]) q.push(nums2[i]); 

        }
        for(auto &i : nums1) i = v[i];
        return nums1; 
    }
};
