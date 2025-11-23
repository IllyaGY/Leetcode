class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <= 1) return 1;
        int k = 0;  
        for(int i = 1; i < nums.size(); i++){
            if(k == 1 && nums[i] > nums[i-1]) return false; 
            else if(k == 2 && nums[i] < nums[i-1]) return false; 
            else if(!k && nums[i] != nums[i-1]) k = nums[i] > nums[i-1] ?  2 : 1; 
        } 
        return true; 
    }
};