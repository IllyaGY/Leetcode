class Solution {
public:
    int canJump(vector<int>& nums) {
        
        nums[nums.size()-1] = 1; 
        for(int i = nums.size()-2; i>=0; i--){
            int temp = nums[i] ;
            nums[i] = 0; 
           
            for(int j = i+1; j <= i + temp && j < nums.size(); j++){
                if(nums[j]) {
                    nums[i] = 1; 
                    break; 
                }

            }
        }
        return nums[0]; 
    }
};