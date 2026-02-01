class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mn = INT_MAX; 
        int mn1 = mn; 
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= mn){
                mn1 = mn; 
                mn = nums[i]; 
            }
            else if(nums[i] <= mn1) {
                mn1 = nums[i]; 
            }
        }
         
        int sum = nums[0] + mn + mn1; 
        
        return sum; 
    }
};
