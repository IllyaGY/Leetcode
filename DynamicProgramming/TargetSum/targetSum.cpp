class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = 0; 
        for(auto &i : nums) s+=i; 
        vector<vector<int>> v(nums.size()+1, vector<int> (2*s + 1, 0)); 
        v[0][s] = 1; 
        for(int i = 1; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                if(j-nums[i-1] >= 0) v[i][j] += v[i-1][j-nums[i-1]]; 
                if(j + nums[i-1] < v[0].size()) v[i][j] += v[i-1][j+nums[i-1]]; 
            } 
        } 
        return s+target < v[0].size() ? v[nums.size()][s+target]: 0 ; 
    }
};
