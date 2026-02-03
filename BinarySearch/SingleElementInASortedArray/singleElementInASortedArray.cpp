class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int md = (i + j) / 2; 
            if(!(!md || nums[md] == nums[md-1]) && !(md + 1 < nums.size() && nums[md] == nums[md + 1]))
                return nums[md]; 
            else { 
                if(md + 1 < nums.size() && nums[md] == nums[md + 1]){
                    if((nums.size() - md)%2) i = md + 1; 
                    else j = md - 1; 
                } 
                else if(!md || nums[md] == nums[md-1]){
                    if(!(md%2)) j = md - 1; 
                    else i = md + 1; 
                } 
            }
        }
        return nums[i]; 
    }
};
