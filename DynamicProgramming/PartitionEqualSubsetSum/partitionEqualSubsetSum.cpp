class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0; 
        for(auto &i : nums) s+=i; 
        if(s%2) return 0; 
        s/=2; 
         
        vector<vector<bool>> taken (nums.size()+1, vector<bool>(s+1, 0)); 
        for(int i = 0; i < taken.size(); i++){
            taken[i][0] = 1; 
        }
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 1; j <= s; j++){
                taken[i][j] = taken[i-1][j] || (j >= nums[i-1] && taken[i-1][j-nums[i-1]]);
            
            }
            if(taken[i][s]) return 1;
        }
        return taken[nums.size()][s]; 
    }
};
