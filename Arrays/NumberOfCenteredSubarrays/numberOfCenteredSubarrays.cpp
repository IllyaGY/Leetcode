class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        
        int c = 0; 
        unordered_map<int, int> st; 
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                st[nums[j]] = i; 
                sum+=nums[j]; 
                if(st.find(sum) != st.end() && st[sum] == i) c++; 
            }
        }
        return c; 
    }
};
