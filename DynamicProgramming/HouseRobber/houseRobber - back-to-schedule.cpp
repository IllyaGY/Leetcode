class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        if(nums.size()>1) nums[1] = std::max(nums[1], nums[0]);  
        for(int i = 2; i < nums.size(); i++){
            prev = i >= 2 ? nums[i-2] : 0;
            int temp = std::max(nums[i] + prev, nums[i-1]); 
            nums[i] = temp; 
        }
        return nums[nums.size()-1];
        
    }
};