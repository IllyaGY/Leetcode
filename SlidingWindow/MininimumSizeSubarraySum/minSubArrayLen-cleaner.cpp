class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0; 
        int s = 0; 
        int l = INT_MAX; 
        while(j < nums.size()){ 
            if(s + nums[j] < target) {
                s+=nums[j]; 
                j++;
            }
            else if (s+ nums[j] >= target){
                while(s + nums[j] >= target){
                    l = min(l,j - i + 1);
                    s-=nums[i]; 
                    i++;
                }
            }
            
            
        }
        return l == INT_MAX ? 0 : l; 
    }
};
