class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i <= j){ 
            while(i + 1 < nums.size() && nums[i] == nums[i+1]) i++; 
            while(j >= 1 && nums[j] == nums[j-1]) j--; 
            int md = (i + j) / 2; 
            if(nums[md] >= nums[i]) {
                if(nums[md] > nums[j])
                    i = md + 1;
                else j = md - 1; 
            }  
            else {
                j = md; 
            }
            
             
            
        }
        return nums[i]; 
    }
};
