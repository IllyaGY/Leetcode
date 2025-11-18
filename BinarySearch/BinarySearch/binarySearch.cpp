class Solution {
public:
    int search(vector<int>& nums, int target) {
        int t = nums.size()-1; 
        int b = 0;  
        while(b <= t){
            int i = (t + b) / 2; 
            if(nums[i] > target) {
                t = i-1;
            } 
            else if(nums[i] < target){
                b = i + 1;
            } 
            else return i; 

            
        
        }
        return -1;
    }
};
