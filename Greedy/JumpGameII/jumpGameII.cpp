class Solution {
public:
    int jump(vector<int>& nums) {
        
        nums[nums.size()-1] = 0; 
        for(int i = nums.size()-2; i>=0; i--){
            int mn = INT_MAX; 
            for(int j = i+1; j <= i + nums[i] && j < nums.size(); j++){
                mn = min(mn, nums[j]); 
            }
            nums[i] = mn < INT_MAX ? mn + 1 : mn; 
        }
        return nums[0]; 
    }
};