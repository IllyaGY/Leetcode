class Solution {
public:
    int rob(vector<int>& nums) {
        
        nums.push_back(0); 
        if(nums.size() < 3) nums.push_back(0); 
        int prev = nums[1]; 
        for(int i = 2; i < nums.size(); i++){
            int temp = nums[i]; 
            nums[i] = max(nums[i] + nums[i-2], max(nums[i-1], nums[i-1] - prev + nums[i]));
            prev = temp; 
        }
        return nums[nums.size()-1]; 
        
    }
};
