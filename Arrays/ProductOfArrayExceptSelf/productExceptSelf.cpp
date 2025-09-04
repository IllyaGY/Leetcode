class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1); 
        vector<int> right(nums.size(), 1); 
        for(int i = 1; i < nums.size(); i++){
            left[i] = nums[i-1] * left[i-1]; 
        }
        for(int j = nums.size()-2; j >= 0; j--){
            right[j] = nums[j+1] * right[j+1];  
        }
        for(int i = 0; i < nums.size(); i++)
            left[i] *= right[i]; 

        return left; 
    }
    
};
