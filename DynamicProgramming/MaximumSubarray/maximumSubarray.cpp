class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0; 
        int s = 0; 
        int mx = nums[0]; 
        while(i < nums.size()){
            s+= nums[i];
            mx = std::max(s, mx);  
            if(s < 0) s = 0; 
            i++; 
        }
        return mx; 
    }
};
